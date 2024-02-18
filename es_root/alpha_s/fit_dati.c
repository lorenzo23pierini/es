void fit_dati(){
    TCanvas *c = new TCanvas("c", "Fit Lorenzo");
    auto frame = c -> DrawFrame(0, 0, 1000, 0.18, "Fit dati #alpha_{s}");
    frame -> GetXaxis() -> SetTitle("Q [GeV]");
    frame -> GetYaxis() -> SetTitle("#alpha_{s}(Q^{2})_{an}");
    frame -> GetXaxis() -> SetTickLength(0.025);
    frame -> GetYaxis() -> SetTickLength(0.025);
    frame -> GetXaxis() -> SetLabelSize(0.02);
    frame -> GetYaxis() -> SetLabelSize(0.02);
        
/*
    TGraphErrors *jade = new TGraphErrors();
    TGraphErrors *lep2 = new TGraphErrors();
    TGraphErrors *cms = new TGraphErrors();

    //JADE
    jade -> SetPoint(0, 14, 0.1536); 
    jade -> SetPoint(1, 22, 0.1407);
    jade -> SetPoint(2, 34.6, 0.1346);
    jade -> SetPoint(3, 38.3, 0.1355);
    jade -> SetPoint(4, 35, 0.1391);
    jade -> SetPoint(5, 43.8, 0.1289);

    jade -> SetPointError(0, 0, pow(10,-4)*sqrt(pow(32,2) + pow(64,2) + pow(28,2) + pow(74,2)));
    jade -> SetPointError(1, 0, pow(10,-4)*sqrt(pow(28,2) + pow(34,2) + pow(21,2) + pow(24,2)));
    jade -> SetPointError(2, 0, pow(10,-4)*sqrt(pow(7,2) + pow(19,2) + pow(31,2) + pow(11,2)));
    jade -> SetPointError(3, 0, pow(10,-4)*sqrt(pow(21,2) + pow(42,2) + pow(38,2) + pow(20,2)));
    jade -> SetPointError(4, 0, pow(10,-4)*sqrt(pow(6,2) + pow(17,2) + pow(33,2) + pow(12,2)));
    jade -> SetPointError(5, 0, pow(10,-4)*sqrt(pow(12,2) + pow(11,2) + pow(38,2) + pow(19,2)));

    jade -> SetMarkerStyle(kFullCircle);
    jade -> SetMarkerSize(1);
    jade -> SetMarkerColor(kBlue);
    jade -> SetLineColor(kBlue);
    jade -> SetLineWidth(2);

    jade -> Draw("P");

    //LEP2
    lep2 -> SetPoint(0, 133, 0.113);
    lep2 -> SetPoint(1, 161, 0.105);
    lep2 -> SetPoint(2, 172, 0.103);
    lep2 -> SetPoint(3, 91, 0.120);

    lep2 -> SetPointError(0, 0, pow(10,-3)*sqrt(pow(3,2)+pow(7,2)));
    lep2 -> SetPointError(1, 0, pow(10,-3)*sqrt(pow(3,2)+pow(6,2)));
    lep2 -> SetPointError(2, 0, pow(10,-3)*sqrt(pow(3,2)+pow(6,2)));
    lep2 -> SetPointError(3, 0, pow(10,-3)*5);

    lep2 -> SetMarkerStyle(kFullCircle);
    lep2 -> SetMarkerSize(1);
    lep2 -> SetMarkerColor(kMagenta);
    lep2 -> SetLineColor(kMagenta);
    lep2 -> SetLineWidth(2);

    lep2 -> Draw("P");

    //CMS
    cms -> SetPoint(0, 474, 0.0936);
    cms -> SetPoint(1, 664, 0.0894);
    cms -> SetPoint(2, 896, 0.0889);
    
    cms -> SetPointError(0, 0, pow(10,-4)*41);
    cms -> SetPointError(1, 0, pow(10,-4)*31);
    cms -> SetPointError(2, 0, pow(10,-4)*34);

    cms -> SetMarkerStyle(kFullCircle);
    cms -> SetMarkerSize(1);
    cms -> SetMarkerColor(kGreen);
    cms -> SetLineColor(kGreen);
    cms -> SetLineWidth(2);

    cms -> Draw("P");
*/

    TGraphErrors *gr = new TGraphErrors();

    //JADE
    gr -> SetPoint(0, 14, 0.1536); 
    gr -> SetPoint(1, 22, 0.1407);
    gr -> SetPoint(2, 34.6, 0.1346);
    gr -> SetPoint(3, 38.3, 0.1355);
    gr -> SetPoint(4, 35, 0.1391);
    gr -> SetPoint(5, 43.8, 0.1289);

    gr -> SetPointError(0, 0, pow(10,-4)*sqrt(pow(32,2) + pow(64,2) + pow(28,2) + pow(74,2)));
    gr -> SetPointError(1, 0, pow(10,-4)*sqrt(pow(28,2) + pow(34,2) + pow(21,2) + pow(24,2)));
    gr -> SetPointError(2, 0, pow(10,-4)*sqrt(pow(7,2) + pow(19,2) + pow(31,2) + pow(11,2)));
    gr -> SetPointError(3, 0, pow(10,-4)*sqrt(pow(21,2) + pow(42,2) + pow(38,2) + pow(20,2)));
    gr -> SetPointError(4, 0, pow(10,-4)*sqrt(pow(6,2) + pow(17,2) + pow(33,2) + pow(12,2)));
    gr -> SetPointError(5, 0, pow(10,-4)*sqrt(pow(12,2) + pow(11,2) + pow(38,2) + pow(19,2)));

    gr -> SetMarkerColor(kBlue);
    gr -> SetLineColor(kBlue);
    gr ->Draw("P");

    //LEP2
    gr -> SetPoint(6, 133, 0.113);
    gr -> SetPoint(7, 161, 0.105);
    gr -> SetPoint(8, 172, 0.103);
    gr -> SetPoint(9, 91, 0.120);

    gr -> SetPointError(6, 0, pow(10,-3)*sqrt(pow(3,2)+pow(7,2)));
    gr -> SetPointError(7, 0, pow(10,-3)*sqrt(pow(3,2)+pow(6,2)));
    gr -> SetPointError(8, 0, pow(10,-3)*sqrt(pow(3,2)+pow(6,2)));
    gr -> SetPointError(9, 0, pow(10,-3)*5);

    gr -> SetMarkerColor(kMagenta);
    gr -> SetLineColor(kMagenta);
    gr ->Draw("P");

    //CMS
    gr -> SetPoint(10, 474, 0.0936);
    gr -> SetPoint(11, 664, 0.0894);
    gr -> SetPoint(12, 896, 0.0889);
    
    gr -> SetPointError(10, 0, pow(10,-4)*41);
    gr -> SetPointError(11, 0, pow(10,-4)*31);
    gr -> SetPointError(12, 0, pow(10,-4)*34);

    gr -> SetMarkerColor(kGreen);
    gr -> SetLineColor(kGreen);
    
    gr -> SetMarkerStyle(kFullCircle);
    gr -> SetMarkerSize(1);
    gr -> SetLineWidth(2);
    gr -> Draw("P");
    
    //Fit
    TF1 *fit = new TF1("fit", "modello_lorenzo", 0, 1000, 1);
    //jade -> Fit("fit");
    //lep2 -> Fit("fit");
    //cms -> Fit("fit");
    //gr -> Fit("fit");

    fit -> SetParameter(0, 0.8);
    cout << fit -> GetParameter(0) << endl;
    cout << fit -> GetParError(0) << endl;

    fit -> SetLineColor(kRed);
    fit -> SetLineStyle(1);
    fit -> SetLineWidth(3);
    fit -> Draw("same");
    //c -> Update();
}

Double_t modello_lorenzo(Double_t *x, Double_t *par) {
    return 1/pow(1-pow(M_E,-pow(x[0],2)/pow(0.3,2)),par[0]);
}