void DivideCanvasExample() {
    // Creare un canvas
    TCanvas *cev = new TCanvas("cev", "Divide Example", 800, 600);

    // Dividere il canvas in 2 righe e 1 colonna
    cev->Divide(2, 1); // colonne, righe

    // Disegnare un istogramma nella prima metà del canvas
    cev->cd(1); // Selezionare il primo pad
    TH1F *histogram1 = new TH1F("histogram1", "Histogram 1", 100, -5, 5);
    histogram1->FillRandom("gaus", 1000);
    histogram1->Draw();

    // Disegnare un istogramma nella seconda metà del canvas
    cev->cd(2); // Selezionare il secondo pad
    TH1F *histogram2 = new TH1F("histogram2", "Histogram 2", 100, -5, 5);
    histogram2->FillRandom("gaus", 1000);
    histogram2->Draw();

    // Aggiornare il canvas
    cev->Update(); // it's not necessary

    // NB: non è possibile lavorare con ilabels del frame direttamente dal canvas, passare per oggetti come TF1, TH1...
}