//First Histogram
{
TH1F hist("hist", "Histogram", 100, -5, 5);
TRandom2 r;

for(int t=0; t<1000; t++){
    hist.Fill(r.Gaus());
}

TCanvas *c1=new TCanvas();
hist.Draw();
hist.Fit("gaus");
}
