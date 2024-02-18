void histogram(){
    TH1F *hist = new TH1F("hist", "Histogram", 100, 0, 15);
    TRandom2 *rand = new TRandom2(3);

    fstream file;
    file.open("data.txt", ios::out);

    for(int i = 0; i < 1000; i++){ //fill the file with random data
        double r = rand->Gaus(5, 1);
        file << r << endl;
    }
    file.close();

    file.open("data.txt", ios::in);

    double value;

    while(1){
        file >> value;
        hist->Fill(value);
        if(file.eof()) break;
    }
    file.close();

    hist->SetFillColor(kGreen-9);

    hist->GetXaxis()->SetTitle("Distribution");
    hist->GetYaxis()->SetTitle("Entries");

    hist->GetXaxis()->SetTitleSize(0.05);
    hist->GetYaxis()->SetTitleSize(0.05);
    hist->GetXaxis()->SetLabelSize(0.05);
    hist->GetYaxis()->SetLabelSize(0.05);

    TF1 *fit = new TF1("fit", "gaus", 0, 15); //for a gaus fit we have 3 parameters 0,1,2
    fit->SetLineWidth(3);
    fit->SetLineColor(kBlue);
    fit->SetLineStyle(2);

    fit->SetParameter(0,40);
    fit->SetParameter(1,5);
    fit->SetParameter(2,1);

    TCanvas *c1 = new TCanvas();
    //c1->SetTickx();
    //c1->SetTicky();
    c1->SetGridx();
    c1->SetGridy();
    hist->SetStats(1); //No automatic legend with the parameter of the histogram
    hist->Draw();
    hist->Fit("fit", "R");

    TLegend *leg = new TLegend(0.5,0.45,0.8,0.75);
    leg->SetBorderSize(1); //No border of the block for the legend
    leg->AddEntry(hist,"Measured Data", "f"); //f for filling
    leg->AddEntry(fit, "Fit Function", "l");
    leg->Draw();

    TLine *l = new TLine(0,20,15,20); //minimum values of x and y and maximum values of x and y
    l->SetLineWidth(2);
    l->SetLineColor(kOrange);
    l->Draw();

    //How to focus into a specific point
    double x0 = 6.3;
    int bin = hist->FindBin(x0);
    double y0 = hist->GetBinContent(bin);

    TArrow *arr = new TArrow(8, 23, x0, y0);
    arr->SetLineWidth(2);
    arr->SetArrowSize(0.02);
    arr->SetLineColor(kRed);
    arr->SetLineStyle(1);
    arr->Draw();

    TLatex *t = new TLatex(8, 23, "Important Point");
    t->Draw();

    double mean = fit->GetParameter(1);
    double sigma = fit->GetParameter(2);
    cout << mean/sigma << endl;

}