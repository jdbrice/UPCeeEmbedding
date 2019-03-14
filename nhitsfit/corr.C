


void corr(){

	TFile *f = new TFile( "output_make.root" );
	TFile *of = new TFile( "output_corr.root", "RECREATE" );
	double bins[] = {0.10, 0.15, 0.16, 0.17, 0.18, 0.19, 0.20, 0.21, 0.22, 0.23, 0.24, 0.25, 0.26, 0.28, 0.30, 0.35, 0.40, 0.50, 0.6, 0.8, 1.0};
	double nbins = 20;
	TH1 * hCorrPos = new TH1F( "hCorrPos", "", nbins, bins );
	TH1 * hCorrNeg = new TH1F( "hCorrNeg", "", nbins, bins );
	TH1 * hCorr = new TH1F( "hCorr", "", nbins, bins );

	string hname="dtpc";
	float cutV = 20;

	for ( int i = 0; i < nbins; i++ ){
		TH1 * hnsl = (TH1*)f->Get( TString::Format( "cdf_sl_n_pt%d", i ) );
		TH1 * hntoe = (TH1*)f->Get( TString::Format( "cdf_%s_n_pt%d", hname.c_str(), i ) );

		TH1 * hpsl = (TH1*)f->Get( TString::Format( "cdf_sl_p_pt%d", i ) );
		TH1 * hptoe = (TH1*)f->Get( TString::Format( "cdf_%s_p_pt%d", hname.c_str(), i ) );

		int ib = hnsl->GetXaxis()->FindBin( cutV - 0.5 );

		float vn = hnsl->GetBinContent( ib ) - hntoe->GetBinContent( ib );
		float vp = hpsl->GetBinContent( ib ) - hptoe->GetBinContent( ib );

		if ( 0 == hntoe->GetBinContent( ib ) && 0 == hptoe->GetBinContent( ib ) ) continue;
		if ( hntoe->GetBinContent( ib ) != hntoe->GetBinContent( ib ) ) continue;
		if ( hptoe->GetBinContent( ib ) != hptoe->GetBinContent( ib ) ) continue;

		cout << "pt=" << i << " : " << hntoe->GetBinContent( ib ) << endl;

		hCorr->SetBinContent( i+1, (vp+vn)/2.0 );
		hCorrPos->SetBinContent( i+1, vp );
		hCorrNeg->SetBinContent( i+1, vn );
	}

	gStyle->SetOptStat(0);
	TCanvas *c = new TCanvas( "c", "c", 900, 600 );
	hCorr->SetLineWidth(2);
	hCorr->SetTitle( TString::Format("nHitsFit >= %d; p_{T} (GeV/c); eff difference (%%) : embedding - data driven", (int)cutV) );
	hCorr->GetYaxis()->SetRangeUser( -0.2, 0.2 );
	hCorr->SetLineColor(kBlack);
	hCorr->Draw();
	c->Print( "nhf_corr.pdf" );
	c->Print( TString::Format("corr_for_%s_at%d.pdf", hname.c_str(), (int)cutV) );
	c->Print( TString::Format("corr_for_%s_at%d.png", hname.c_str(), (int)cutV) );
	of->cd();
	hCorr->Write();
	hCorrPos->Write();
	hCorrNeg->Write();
}