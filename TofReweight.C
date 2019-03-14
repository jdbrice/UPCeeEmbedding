
TH2 * hEff = NULL;

void TofReweight(){
	TDirectory * gd = gDirectory;
	TFile * ff = new TFile("/Users/jdb/bnl/work/upc/data/BTofSim/ana_FF.root");
	hEff = (TH2*)ff->Get( "hceffeta" );

	cout << "hEff = " << hEff << endl;

	gDirectory = gd;
}

double nhfWeight( float nhf, float eta ){

	nhf = (int) nhf;
	if ( nhf < 15 ) return 0;
	if ( nhf > 46 ) return 0;

	int ibx = hEff->GetXaxis()->FindBin( eta );
	int iby = hEff->GetYaxis()->FindBin( nhf );
	return hEff->GetBinContent( ibx, iby );

}