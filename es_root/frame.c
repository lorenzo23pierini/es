void frame() {
    // Creare un canvas
    TCanvas *canvas = new TCanvas("myCanvas", "My Canvas", 800, 600);

    // Creare un frame all'interno della canvas
    TFrame *frame = new TFrame();
    frame->Draw();

    // Accedere agli oggetti dell'asse x e y del frame
    TGaxis *xAxis = frame->GetXaxis();
    TGaxis *yAxis = frame->GetYaxis();

    // Ridimensionare i caratteri dei numeri sull'asse x e sull'asse y
    xAxis->SetLabelSize(0.02); // Imposta la dimensione dei numeri sull'asse x
    yAxis->SetLabelSize(0.02); // Imposta la dimensione dei numeri sull'asse y

    // Aggiornare il canvas
    canvas->Update();
}
 // E' possibile lavorare anche con frame direttamente