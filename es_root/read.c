void read(){
    TFile *file = new TFile("output.root", "READ");

    TH1F *hist = (TH1F*)file->Get("hist"); //Get the hist from the file

    hist->Draw();

    //file->Close(); //If you close the file you see only an empty canvas because the file gets closed before the hist is print out by the program
}