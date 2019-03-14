
#include "TLorentzVector.h"
#include "TVector3.h"

double pairMass( float pt1, float eta1, float phi1, float pt2, float eta2, float phi2 ) {
	TLorentzVector lv1, lv2, lv;
	lv1.SetPtEtaPhiM( pt1, eta1, phi1, 0.000511 );
	lv2.SetPtEtaPhiM( pt2, eta2, phi2, 0.000511 );
	lv = lv1 + lv2;
	return lv.M();
}

double pairPt( float pt1, float eta1, float phi1, float pt2, float eta2, float phi2 ) {
	TLorentzVector lv1, lv2, lv;
	lv1.SetPtEtaPhiM( pt1, eta1, phi1, 0.000511 );
	lv2.SetPtEtaPhiM( pt2, eta2, phi2, 0.000511 );
	lv = lv1 + lv2;
	return lv.Pt();
}

double pairPt2( float pt1, float eta1, float phi1, float pt2, float eta2, float phi2 ) {
	TLorentzVector lv1, lv2, lv;
	lv1.SetPtEtaPhiM( pt1, eta1, phi1, 0.000511 );
	lv2.SetPtEtaPhiM( pt2, eta2, phi2, 0.000511 );
	lv = lv1 + lv2;
	return lv.Pt()*lv.Pt();
}

double pairRapidity( float pt1, float eta1, float phi1, float pt2, float eta2, float phi2 ) {
	TLorentzVector lv1, lv2, lv;
	lv1.SetPtEtaPhiM( pt1, eta1, phi1, 0.000511 );
	lv2.SetPtEtaPhiM( pt2, eta2, phi2, 0.000511 );
	lv = lv1 + lv2;
	return lv.Rapidity();
}

double deltaPhi( float pt1, float eta1, float phi1, float pt2, float eta2, float phi2 ){

	TLorentzVector lv1, lv2, lv;
	lv1.SetPtEtaPhiM( pt1, eta1, phi1, 0.000511 );
	lv2.SetPtEtaPhiM( pt2, eta2, phi2, 0.000511 );
	lv = lv1 + lv2;

	// return fabs(lv.DeltaPhi( lv1 ));
	return fabs( fabs(lv.DeltaPhi( lv1 )) - TMath::Pi()/2);

	return 0;
}

double CosTheta( float pt1, float eta1, float phi1, float pt2, float eta2, float phi2 ){
	TLorentzVector lv1, lv2, lv;
	lv1.SetPtEtaPhiM( pt1, eta1, phi1, 0.000511 );
	lv2.SetPtEtaPhiM( pt2, eta2, phi2, 0.000511 );
	lv = lv1 + lv2;

	TLorentzVector lvPositron = lv2;
	lvPositron.Boost( -(lv.BoostVector()) );
	TVector3 vbeam(0, 0, 1.0);

	TVector3 vPositron( lvPositron.Px(), lvPositron.Py(), lvPositron.Pz() );
	float costheta = cos( vPositron.Angle( vbeam ) );	
	return costheta;
}

