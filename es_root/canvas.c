void canvas() {
    TCanvas *canvas = new TCanvas("canvas", "Prova");
    canvas -> DrawFrame(0, 0, 100, 100);
    // canvas -> SetLogx(kTRUE); // scala logaritmica
    canvas ->SetGrid(kTRUE,kTRUE);
}