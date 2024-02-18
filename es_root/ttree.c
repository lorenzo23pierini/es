void ttree(){
    fstream file;
    file.open("data4.txt", ios::in);

    double x, y;

    TFile *output = new TFile("data4.root", "recreate");

    TTree *tree = new TTree("tree", "Cluster"); //Variable, Name that you wnat
    tree->Branch("x", &x, "x/D"); //D double, F float, I int
    tree->Branch("y", &y, "y/D");

    while(1){
        file >> x >> y;
        cout << x << " " << y << endl;
        tree->Fill();
        if(file.eof()) break;
    }

    output->Write();
    output->Close();
    file.close();
}