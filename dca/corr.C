


void corr(){

	TFile *f = new TFile( "output_make.root" );
	TFile *of = new TFile( "output_corr.root", "RECREATE" );
	double bins[] = {0.10, 0.15, 0.16, 0.17, 0.18, 0.19, 0.20, 0.21, 0.22, 0.23, 0.24, 0.25, 0.26, 0.28, 0.30, 0.35, 0.40, 0.50, 0.6, 0.8, 1.0};
	double nbins = 20;
	TH1 * hCorr = new TH1F( "hCorr", "", nbins, bins );

	for ( int i = 0; i < nbins; i++ ){
		TH1 * hsl = (TH1*)f->Get( TString::Format( "cdf_sl_n_pt%d", i ) );
		TH1 * htoe = (TH1*)f->Get( TString::Format( "cdf_dtoe_n_pt%d", i ) );

		int ib = hsl->GetXaxis()->FindBin( 1.0 );

		float v = hsl->GetBinContent( ib ) - htoe->GetBinContent( ib );

		hCorr->SetBinContent( i+1, v );
	}

	hCorr->Draw();
	of->cd();
	hCorr->Write();
}
