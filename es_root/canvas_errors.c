void canvas_errors() {
    TCanvas *c = new TCanvas("c", "Canvas");
    c -> DrawFrame(0,0,100,100);
    c -> SetGrid(1,1);

    TGraphErrors *gr = new TGraphErrors("gr", "Prova");
    gr -> SetPoint(0, 1, 1);
    gr -> SetPoint(1, 50, 51);
    gr -> SetPointError(0, 0.1, 0.2);
    gr -> SetPointError(1, 0.1, 0.2);
    gr -> Draw("*P"); //A automatic zoom on the xy axes due to the points distribution
}