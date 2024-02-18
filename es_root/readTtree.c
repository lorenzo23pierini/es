void readTtree(){
    TCanvas *canvas = new TCanvas("canvas", "Multiple Histograms", 800, 600);
    //TCanvas *canvas = new TCanvas();

    TFile *input = new TFile( "data4.root", "read");
    TTree *tree = (TTree*)input->Get("tree");//Get the TTree from TFile input (like for the hist)
    TH1F *histx = new TH1F("histx", "Histogram", 100, 0, 80);
    TH1F *histy = new TH1F("histy", "Histogram", 100, 0, 80);

    int entries = tree->GetEntries(); //Number of entries in the tree (We have 4 rows, so 4 entries)
    cout << entries << endl;

    double x, y;
    tree->SetBranchAddress("x", &x);
    tree->SetBranchAddress("y", &y);

    for(int i = 0; i < entries; i++){
        tree->GetEntry(i);
        cout << x << " " << y << endl;
        histx->Fill(x);
        //histy->Fill(y);
    }

    //input->Close(); //Non va chiuso il file

    //--------Aesthetics of the environment--------
    //I choose to print all the two hist(x,y) on the same canvas
    histx->SetTitle("Multiple Histograms");
    histx->SetLineColor(kRed);
    histx->Draw();

    //canvas->Update(); //It isn't necessary

    histy->Draw("SAME");
    histx->SetStats(0);

    TLegend *leg = new TLegend(0.8,0.8,0.95,0.95);
    leg->SetBorderSize(1); 
    leg->AddEntry(histx,"x", "l"); 
    leg->AddEntry(histy, "y", "l");
    leg->Draw();
}