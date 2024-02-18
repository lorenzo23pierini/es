//Root CERN

//hist.c
{
TH1F hist("hist", "Histogram", 100, -5, 5);
TRandom2 r;

for(int t=0; t<1000; t++){
    hist.fill(r.Gaus());
}

TCanvas *c1=new TCanvas();
hist.Draw();
hist.fit("gaus");
}

//graph.c
{
    double x[5]={1, 2, 3, 4, 5};
    double y[5]={1, 4, 9, 16, 5};

    TGraph gr(5, x, y);

    TCanvas c1;
    gr.Draw("AC");
}

//Function
//tut1.c
void tut1(){ //Nothing or the same name of the file.c
    TH1F *hist= new TH1F("hist", "Histogram", 100, 0, 100);

    hist->Fill(10);
    hist->FIll(90);

    hist->GetXaxis()->SetTitle("x Axis (Bin)");
    hist->GetXaxis()->SetTitle("y Axis (Entries)");

    TCanvas *c1_= new TCanvas();
    hist->Draw();
}

//tut2.c
void tut2(){
    double x[5]={1,2,3,4,5};
    double y[5]={1,4,9,16,25};

    gr->SerMarkerStyle(4); //1,2,3,4 differente types of marker, kFullCircle
    gr->SetMarkerSize(1);

    TGraph *gr= new TGraph(5, x, y);
    TCanvas *c1= new TCanvas();
    gr->Draw("A"); //parameter A: draw everything of the graph
                   //AL: all data points are connect with line 
                   //ALP: also points marked
                   //AC: draws curve throught the data points
}                   

//Histogram fill with data from a data input file
//tut3.c
void tut3(){
    TH1F *hist=new TH1F("hist", "Histogram", 100, 0, 100);

    hist->GetXaxis()->SetTitle("Grade");
    hist->GetYaxis()->SetTitle("Entries");

    fstream file;
    file.open("data.txt", ios:in);

    double value;

    while(1){
        file>>value;
        hist->Fill(value);
        if(file.eof()) break;
    }

    file.close();

    TCanvas *c1=new TCanvas();
    hist->Draw();
}

//dat.txt
3
5
1
2
3
6
5
4
1
2
5
4
8
9

//Plotting data with TGraph
//tut4.c
void tut4(){
    TGraph *gr= new TGraph(/*remove all constructor's parameters if you don't know how the entries are*/);
    gr->SetMarkerStyle(4); //1,2,3,4 differente types of marker, kFullCircle
    gr->SetMarkerSize(1);
    gr->SetLineWidth(2);
    gr->SetLineColor(kRed);

    gr->SetTitle("Graph");
    gr->GetXaxis()->SetTitle("X Values");
    gr->GetYaxis()->SetTitle("Y Values");

    fstream file;
    file.open("data1.txt" ios:in);

    while(1){
        double x, y;
        file>>x>>y;
        gr->SetPoint(gr->GetN(), x, y);
        if (file.eof()) break;
    }
    file.close();

    TCanvas *c1= new TCanvas();
    gr->Draw("ALP");
}     

//data1.txt
1 1
2 4
3 9
4 16
5 25

//Random Data
//tut5.c
void tut5(){
    TRandom2 *rand= new TRandom2(); //automatically TRandom2 sets seed to 1
    TH1F *hist= new TH1F("hist", "Histogram", 0, 1, 7);

    for(int i=0, i<3; i++){
        double r=rand->Rndn();
        cout<<r<<endl;
        hist->Fill(r);
    }

    TCanvas *c1=new TCanvas();
    hist->GetYaxis()->SetRangeUser(0,200);
    hist->Draw();
}

//Gaussian Distribution: Generating and Fitting
//tut6.c
void tut6(){
    TH1F *hist= new TH1F("hist", "Histogram", 100, 0, 10);
    Trandom2 *rand= new TRandom2(3);

    fstream file;
    file.open("data.txt", ios::in);

    for(int i=0; i<1000; i++){
        rand->Gaus(5,1); //Mean:5, Std.Dev:1
    }
    f.close();

    file.open("data.txt", ios::in);

    double value;

    while(1){
        file->value;
        hist->Fill(value);
        if(file.eof()) break;
    }

    file.close();

    hist->GetXaxis()->SetTitle("Distribution");
    hist->GetXaxis()->SetTitle("Distribution");

    TCanvas *c1=new TCanvas();
    hist->Draw();
}

//Fit Function and Parameters
//tut7.c
void tut7(){
    TH1F *hist= new TH1F("hist", "Histogram", 100, 0, 10);
    Trandom2 *rand= new TRandom2(3);

    fstream file;
    file.open("data.txt", ios::in);

    for(int i=0; i<1000; i++){
        rand->Gaus(5,1); //Mean:5, Std.Dev:1
    }
    f.close();

    file.open("data.txt", ios::in);

    double value;

    while(1){
        file->value;
        hist->Fill(value);
        if(file.eof()) break;
    }

    file.close();

    hist->GetXaxis()->SetTitle("Distribution");
    hist->GetXaxis()->SetTitle("Distribution");

    TCanvas *c1=new TCanvas();
    hist->Draw();

    //hist->Fit("gaus"); //you can do that also by the pannel

    TF1 *fit=new TF1("fit", "gaus", 0, 10); //4, 6 range
    //Usually is not easy that fit converge, so setting parameters is necessary

    //fit->SetParameter()//for each parameter
    //For a gaussian 3 parameters: Constant, Mean, Std.Dev.
    fit->SetParameter(0, 40); //parameter0: Hight of the hinstogram
    fit->SetParameter(1, 5); //parameter1: Mean value
    fit->SetParameter(2, 1); //parameter2: Std.Dev
    //instead of gaus you can put the name of the function
    hist->Fit("fit","R");

    double mean= fit->GetParameter(1);
    double sigma=fit->GetParameter(2);

    cout<<mean/sigma<<endl;
}

//Legend to an Histogram
//tut8.c
void tut7(){
    TH1F *hist= new TH1F("hist", "Histogram", 100, 0, 10);
    Trandom2 *rand= new TRandom2(3);

    fstream file;
    file.open("data.txt", ios::in);

    for(int i=0; i<1000; i++){
        rand->Gaus(5,1); //Mean:5, Std.Dev:1
    }
    f.close();

    file.open("data.txt", ios::in);

    double value;

    while(1){
        file->value;
        hist->Fill(value);
        if(file.eof()) break;
    }

    file.close();

    hist->GetXaxis()->SetTitle("Distribution");
    hist->GetXaxis()->SetTitle("Distribution");

    TCanvas *c1=new TCanvas();
    hist->SetStats(0);//Not show the automatic legend of the histogram
    hist->Draw(); //Before Draw

    TLegend *leg= new TLegend(0.7,0.7, 0.9,0.9);
    leg->AddEntry(&hist, "Measured Data", "l"); //l line, p points, f filling, lp, lf, ...
    leg->AddEntry->(fit, "Fit Function", "l");
    leg->Draw();

    TF1 *fit=new TF1("fit", "gaus", 0, 10); 

    fit->SetParameter(0, 40); 
    fit->SetParameter(1, 5); 
    fit->SetParameter(2, 1); 
    
    hist->Fit("fit","R");

    double mean= fit->GetParameter(1);
    double sigma=fit->GetParameter(2);

    cout<<mean/sigma<<endl;
}

//Beautify your Plots
//tut9.c (lesson 11)
    hist->SetFillColor(kGreen-9) //increase the intensity of the color
    hist->GetXaxis()->SetTitleSize(0.05);// select the size of the name of the axis 
    hist->GetYaxis()->SetTitleSize(0.05);
    hist->GetXaxis()->SetLabelSize(0.05);// select the size of the label (number) in the axis
    hist->GetYaxis()->SetLabelSize(0.05);

    ...

    fit->SetLineWidth(3);
    fit->SetLineColor(kBlue);
    fit->SetLineStyle(1); //1,2,3

    TCanvas *c1 = new TCanvas();
    c1->SetTickx();
    c1->SetTicky();
    c1->SetGridx(); //Grid for the canva
    c1->SetGridy();
    hist->SetStats(0);
    hist->Draw();

    hist->Fit("gaus", "R");

    TLegend *leg = new TLegend(0.5,0.5,0.8,0.8);
    leg->SetBorderSize(0); //No border of the block for the legend
    leg->AddEntry(hist,"Measured Data", "f"); //f for filling
    leg->AddEntry(fit, "Fit Function", "l");
    leg->Draw();

//Plotting Data with error bars
//tut10.c
void tut10(){
    TCanvas *c1=new TCanvas();
    TGraphErrors *gr=new TGraphErrors();

    fstream file;
    file.open("data3.txt",ios::in);

    double x, y, ex, ey;
    int n=0;
    while(1){
        file >> x >> y >> ex >> ey;
        n=gr->GetN();//Number of points (I don't know how much it is)
        gr->SetPoint(n, x, y);
        gr->SetPointError(n, ex, ey); //this option is more than the TGraph
        if (file.eof()) break;
    }

    gr->Draw("A*"); //draw the point like stars

    TF1 *fit = new TF1("fit", "pol1", 0, 5); //Not gaus but pol1 (linear)
    gr->Fit("fit");
}
//data3.txt
1 1 0 0.1
2 2 0 0.2
3 3 0 0.3
4 4 0 0.4
5 5 0 0.5

//Adding Text and Decrations to Plots
//tut11.c
...
    TLine *l = new TLine(0,20,15,20); //minimum values of x and y and maximum values of x and y
    l->SetLineWidth(2);
    l->SetLineColor(kOrange);
    l->Draw();

    //How to focus into a specific point
    double X0 = 0.3; 
    int bin = hist->FindBin(X0);
    double y0 = hist->GetBinContent(bin);

    TArrow *arr = new TArrow(10, 50, x0, y0);
    arr->Draw();

    TLatex *t = new TLatex(8, 23, "Important Point");
    t->Draw();
//histogram.c

//Creating User-Defined Functions
//tut12.c
...
    TF1 *func = new TF1("func", "[0]+[1]*x", 0, 5) //form of the function and the interval of defintion
    //func->Draw(); //If you don't set the parameters root puts them equal to zero
    func->SetParameter(0, 1);
    func->SetParameter(1,2);
    func->Draw();

    TF1 *func = new TF1("func", "exp(-[1]*x)*[0]*sin(x)", 0, 10*TMath::Pi());

    func->SetTitle(""); //If you don't want the title in the canvas

    func->SetParameter(0, 1);
    func->SetParameter(1, 0.1);

    func->GetXaxis()->SetTitle("Test");
    func->GetYaxis()->SetTitle("Test");

    func->Draw();

//Exporting Plots
//tut13.c
...//after drawing the func
    c1->Print("func.png");
    c1->Print("func.pdf");
    c1->Print("func.tex"); //Latex!!!!
    
    //change tha canvas dimensions
    TCanvas *c1 = new TCanvas("c1", "Canvas", 400, 400);
    c1->SetLeftMargin(0.15); //0.1 is the default

//Storing and Loading Object with TFile
//tut14.c
//tfile.c
void tfile(){
    TFile *file = new TFile("output.root", "RECREATE");

    TH1F *hist = new TH1F("hist", "Histogram", 100, 0, 100);

    hist->Fill(10);
    hist->Fill(90);

    file->Write();
    file->Close();

    //hist->Draw();
}
//You create a .root file, that if you run by root create a file that you can see from TBrowser inside root bash.
//read.c
void read(){
    TFile *file = new TFile("output.root", "READ");

    TH1F *hist = (TH1F*)file->Get("hist"); //Get the hist from the file

    hist->Draw();

    //file->Close(); //If you close the file you see only an empty canvas because the file gets closed before the hist is print out by the program
}
//You can read from .root file and print out the hist, that is inside the TFile.

//--------------------------------------------------------------------------------------------------------------------------------------------------
//Storinf Data in TTree
//tut15.c
//ttre.c
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
//data4.txt
3 6
5 9
1 4
13.5 59.7564
//Create a TFile called data4.root in which there is a TTree with 2 banches x, y (automatically they have the hinstograms inside)

//Reading Data from TTree
//tut16.c
//readTtree.c
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
}

//-------------------------------------------------------------------------------------------------------------------------------
//Creating 2D Histograms with TH2F
//tut17.c
//hist2D.c
void tut17(){
    TCanvas *c1 = new TCanvas();

    gStyle->SetPalette(kRainBow); //Include palette

    TH2F *hist = new TH2F("hist", "Histogram",100, -1, 1, 100, -1, 1); //bin, x_min
    hist->SetStats(0);

    TRandom *rand = new TRandom(10);
    
    for(int i=0; i<1e6; i++){
        double x = rand->Gaus();
        double y = rand->Gaus();

        hist->Fill(x,y);
    }

    hist->GetXaxis()->SetTitle("x [cm]");
    hist->GetYaxis()->SetTitle("y [cm]");
    hist->GetZaxis()->SetTitle("Entries");
    
    hist->SetContour(1000)//More shade of color
    hist->Draw("colz"); //colz 
}

//Compiling yout ROOT Script
//tut18.c Lesson 20
void tut18(){
    TStopwatch t; //It's a variable that shows how much time it's needed for the execution of the program
    TRandom2 *r = new TRandom2();

    double x;

    for(int i = 0; i < 1e9; i++){
        x += r->Rndm(); //Before we have used Gaus(), now we are adding to x 1e9 random numbers
    }

    cout << x <<endl;

    t.Print();
}
//If we add 1e9 numbers, run time is long and t shows this to us.
//So ROOT gives us the possibility to compile our scripts before their running, to increse the performance of our macros
//We can compile only using: root tut18.c+ //adding a '+' after our macro name
//if we compile our macro, it's necessary include the ROOT libraries, and also using namespace std
/*So, in summary:
-root my_macro.c+: 
    Compiles the script into a shared library before execution, allowing you to reuse functions or classes interactively.
-root my_macro.c: 
    Interprets the script directly without compilation, suitable for quick testing or simple scripts.*/

//Plotting Histograms with TProfile
//tut19.c
void tut19(){
    TCanvas *c2 = new TCanvas();

    TProfile *hprof = new TProfile("hprof","Profile", 100, 0, 10, "S"); //'S' show std.dev in both direction
    
    //hprof->Fill(1, 4);
    //hprof->Fill(1, 6);

    TRandom2 *rand = new TRandom2();

    for(int i = 0; i < 100; i++){
        //hprof->Fill(1, rand->Rndm());
        hprof->Fill(rand->Rndm()*10, rand->Rndm());
    }

    hprof->Draw();
}

//Using TCut for TTree Analysis
//tut20.c
void write(){
    TFile *output = new TFile("tut20.root", "recreate");

    TTree *tree = new TTree("tree", "tree");

    double x, y;

    tree->Branch("x", &x, "x/D");
    tree->Branch("y", &y, "y/D");

    TRandom2 *r = new TRandom2();

    for(int i = 0; i < 1e6; i++){
        x = 1+r->Rndm();
        y = x*2;
        tree->Fill();
    }

    output->Write();
    output->Close();
}

void cut(){
    TCut cut1 = "x > 5";
    TCut cut2 = "x < 6";

    TFile *input = new TFile("tut20.root", "read");

    TTree *tree = (TTree*)input->Get("tree");

    tree->Draw("y", cut1 || cut2); //Only branch y, Add cut1 to apply the restriction
}

void tut20(){
    write();
    cut();
}


//Using TChain
//tut21.c
void write(TString filename){
    TFile *output = new TFile(filename, "recreate"); //The name of the file now it's a variable called 'filename'

    TTree *tree = new TTree("tree", "tree");

    double x, y;

    tree->Branch("x", &x, "x/D");
    tree->Branch("y", &y, "y/D");

    TRandom2 *r = new TRandom2();

    for(int i = 0; i < 1e6; i++){
        x = 1+r->Rndm();
        y = x*2;
        tree->Fill();
    }

    output->Write();
    output->Close();
}

void chain(){
    TChain *chi = new TChain("tree");

    ch1->Add("tut21a.root");
    ch1->Add("tut21b.root");

    double x;

    ch1->SetBranchAddress("x", &x);

    int entries = ch1->GetEntries();

    TH1F *hist = new TH1F("hist", "Histogram", 100, 1, 10);

    for(int i = 0; i < entries; i++){
        ch1->GetEntry(i);
        hist->Fill(x);
    }

    TCanvas *c1 = new TCanvas();
    hist->Draw();
}

void tut21(){
    write("tut21a.root"); //Two files from the same TTree
    write("tut21b.root");
}

//Using Inputs Parameters
//tut23.c
void tut23(){ //ok
    int a = 5;
    cout << a << endl;
}

void tut23(int a = 5){ //ok
    cout << a << endl;
}

void tut23(int a){ //error due to no value for a
    cout << a << endl;
}
//It's possible run: root 'tut23.c(5)'

void tut23(int a, int b){
    cout << a*b << endl;
}
//root 'tut23.c(5,10)'

void tut23(TString filename){
    TFile *file = new TFile(filename);
}
//root 'tut23.c("test.root")' //Double quotes are necessary

//Histogram Stacks and Useful Tricks
//tut24.c
void tut24(){
    THStack *hstack = new THStack("hstack", "histogram Stack; x title: y title"); 
    //It is usefull to show two histograms in the same canvas

    TH1F *hist = new TH1F("hist", "Histogram; x title; y title", 100, -10, 10); //Much faster to set the title of the axises
    TH1F *hist2 = new TH1F("hist2", "Histogram 2; x title; y title", 100, -10, 10);
    
    hstack->Add(hist);
    hstak->Add(hist2);

    hist->FillRandom("gaus", 1e4); //automatically 5000 events (we can choose the number of entries)
    hist2->FillRandom("gaus", 1e4);
    
    TCanvas *c1 = new TCanvas();
    hist->Draw();
    hist2->Draw("same");

    TCanvas *c2 = new TCanvas();
    hstack->Draw("nostack"); //Not the same high
}

//-----------------------------------------------------------------------------------------------------------------------------------
//Using 3D Vectors in ROOT with TVector3 Class
//tut26.c
void tut26(){
    TVector3 v1(1,2,3);

    cout << v1.X() << endl; //or v1[0]
    cout << v1.Y() << endl; //or v2[0]
    cout << v1.Z() << endl; //or v3[0]

    v1.Print(); //It prints the cartesian and polar coordinates 
    //Output is: 
    //TVector3 A 3D physics vector (x,y,z)=(1.000000,2.000000,3.000000) (rho,theta,phi)=(3.741657,36.699225,63.434949)

    double rho = v1.Mag();
    double theta = v1.Theta()*180/TMath::Pi(); //In degree
    double phi = v1.Phi(); //Automatically in radiant

    cout << rho << "\t" << theta << "\t" << phi << endl;

    v1.RotateZ(90*TMAth::Pi()/180.);

    v1.Print();

    TVector3 v2; //Instead inserting the coordinates directly in the constructor
    v2.SetX(4);
    v2.SetY(5);
    v2.SetZ(6);

    v2.Print();

    TVector3 v3;
    v3.SetZ(10);
    v3.SetTheta(10*TMath::Pi()/180);
    v3.SetPhi(10*TMath::Pi()/180);

    v3.Print();

    //Sum of TVector3
    TVector3 v4 = v1 + v2;

    v4.Print();

    //Scalar product of TVector3
    cout << v1.Dot(v2) << endl;

    //Angle between two TVector3
    cout << v1.Angle(v2)*180./TMath::Pi() << endl;
}

//How to Use TClonesArray
//tut27.c
void write(){
    TClonesArray *arr = new TClonesArray("TVector3");
    TFile *file = new TFile("file.root", "recreate");
    TTree *tree = new TTree("tcl", "tcl");

    tree->Branch("array", &arr);

    TRandom2 *rand = new TRandom2(1);

    for(int i = 0; i < 100; i++){
        arr->Clear();

        for(int j = 0; j < 1000; j++){
            double x = rand->Rndm();
            double y = rand->Rndm();
            double z = rand->Rndm();

            new (ar[j]) TVector3(x,y,z);
        }

        tree->Fill();
    }
    file->Write();
    file->Close();
}

void read(){
    TFile *file = new TFile("file.root");

    TTree *tree = (TTree*)file->Get("tcl");

    TClonesArray *arr = new TClonesArray("TVector3");

    tree->SetBranchAddress("array", &arr);

    int entries = tree->GetEntries();
    for(int i = 0; i < entries; i++){
        tree->GetEntry(i);
        int lines = arr->GetEntries();

        for(int j = 0; j < lines; j++){
            TVector3 *vec = (TVector3*)Arr->At(j);
            cout << vec->X() << endl;
        }
    }
}

void tut27(){
    write();
    read();
}

//-----------------------------------------------------------------------------------------------------------------------
//Using ROOT in Python with PyROOT
//tut28.c
//pyRoot.py
from ROOT import *

h1 = TH1F("h1", "Random Numbers", 200, -5, 5)
h1.FillRandom("gaus")

c1=TCanvas()
h1.Draw()
#input()
c1.Print("c1.pdf") //Create a .pdf file in the same directory of pyRoot.py
//python pyRoot.py //esecute directly the canvas

//----------------------------------------------------------------------------------------------------------------------
//Drawing & Animations
//tut.28.c
void tut28(){
    TCanvas *c1 = new TCanvas("c1", "c1", 300, 300);

    TEllipse *el = new TEllipse(0.5, 0.5, 0.1, 0.1);
    el->SetFillColor(kBlack);

    gSystem->Unlink("tut28.gif");

    for(int i = 0; i < 50; i++){
        el->SetX1(0.5+i*0.1);
        el->Draw();
        c1->Update();
        c1->Print("tut28.gif+");
        sleep(1); //Wait one second per step
    } 
}

//tut29.c
void tut29(){
    TCanvas *c1 = new TCanvas();
    TH1F *hist = new TH1F("hist", "Histogram", 100, -5, 5);

    gSystem->Unlink("tut29.gif");

    TRandom *r1 = new TRandom();

    for(int i = 0; i < 1e5; i++){
        double val = r1->Gaus();
        hist->Fill(val);
        c1->Update();
        if(i%100==0){
            hist->Draw();
            hist->Fit("gaus");
            c1->Modified();
            c1->Print("tut29.gif+");
        }
        //sleep(1);
    }
}

//Finding roots of functions
//tut30.c
void tut30(){
    TF1 *f = new TF1("f", "[0]*cos([1]+x)", -5, 5);

    f->SetParameter(0, 1);
    f->SetParameter(1, 1);

    TCanvas *c1 = new TCanvas();
    f->Draw();

    ROOT::Math::RootFinder finder;
    finder.Solve(*f, -5, 0); //Where it must to search from -5 to 0
    double solution = finder.Root();
    cout << solution << endl;

    finder.Solve(*f, 0, 5);
    double solution2 = finder.Root();
    cout << solution2 << endl;

    TLine *l1 = new TLine(-5, 0. 5, 0);
    TLine *l2 = new TLine(solution, -2., solution, 2);
    TLine *l3 = new TLine(solution2, -2, solution2, 2);

    l1->Draw();
    l2->Draw();
    l3->Draw();
}

//Histogram Arithmetic
//tut31.c
void tut31(){
    TH1F *hist1 = new TH1F("hist1", "Histogram", 100, -10, 10);

    hist1->FillRandom("gaus");
    //hist1->Scale(-10); //Inverte the scale of the histogram
    //hist1->Scale(1/hist1->GetEntries()); //Normalise the area
    hist1->Scale(1/hist1->GetMaximum());

    TCanvas *c1 = new TCanvas();
    hist1->Draw("hist"); //Annulla Scale
}

//tut32.c
void tut32(){
    TH1F *hist1 = new TH1F("hist1", "Histogram", 100, -10, 10);
    TH1F *hist2 = new TH1F("hist2", "Histogram", 100, -10, 10);

    hist1->FillRandom("gaus");
    hist2->FillRandom("gaus");

    hist1->Add(hist2);
    hist1->Add(hist2);
    hist1->Add(hist2);
    hist1->Add(hist2);
    ... //Number of entries increse with a factor due to the number of Add()

    TCanvas *c1 = new TCanvas();
    hist1->Draw("hist"); //Annulla Scale
}

//tut32.c
void tut32(){
    TH1F *hist1 = new TH1F("hist1", "Histogram", 100, -10, 10);
    TH1F *hist2 = new TH1F("hist2", "Histogram", 100, -10, 10);

    hist1->FillRandom("gaus");
    hist2->FillRandom("gaus");

    TH1F *hist3 = new TH1F();

    *hist3 = (*hist1)/(*hist2); //It's not esactly one for the statistical fluttuation
    //*hist3 = (*hist1)*(*hist2);
    
    TCanvas *c1 = new TCanvas();
    hist3->Draw("hist"); //Annulla Scale
}

//--------------------------------------------------------------------------------------------------------------------------------

//Drawing 3D Object
//tut33.c
//box.c
void tut33(){
    TCanvas *c1 = new TCanvas();

    TGLViewer *view = (TGLViewer*)gPad->GetViewer3D();

    TGeoManager *man = new TGeoManager();

    TGeoVolume *top = gGeoManager->MakeBox("BOX", NULL, 10, 10, 10); //name, material, xlenght, ylenght, zlenght

    man->SetTopVolume(top);

    man->CloseGeometry();

    top->Draw();
}

//tut34.c
void tut34(){
    TCanvas *c1 = new TCanvas();

    TGLViewer *view = (TGLViewer*)gPad->GetViewer3D();

    TGeoManager *man = new TGeoManager();

    TGeoVolume *top = gGeoManager->MakeBox("TOP", NULL, 10, 10, 10); //name, material, xlenght, ylenght, zlenght
    TGeoVolume *box = gGeoManager->MakeBox("BOX", NULL, 1, 1, 0.2);
    //Also we can write
    //TGeoVolume *top = man->MakeBox("TOP", NULL, 10, 10, 10); //name, material, xlenght, ylenght, zlenght
    //TGeoVolume *box = man->MakeBox("BOX", NULL, 1, 1, 0.2);

    man->SetTopVolume(top);

    top->AddNode(box, 0);

    man->CloseGeometry();

    //top->Draw();  
    top->Draw("ogl") //Two pop up, one is canvas and another is for 3D details (light, ...)
}

//tut35.c
void tut35(){
    TCanvas *c1 = new TCanvas();

    TGLViewer *view = (TGLViewer*)gPad->GetViewer3D();

    TGeoManager *man = new TGeoManager();

    TGeoVolume *top = man->MakeBox("TOP", NULL, 10, 10, 10); //name, material, xlenght, ylenght, zlenght
    TGeoVolume *box = man->MakeBox("BOX", NULL, 1, 1, 0.2);

    box->SetLineColor(kGreen);

    TGeoHMatrix *trans_rot = new TGeoHMatrix("TRANSROT");
    trans_rot->RotateX(45.);
    trans_rot->SetDz(2.);

    TGeoVolume *tube = man->MakeTube("TUBE", NULL, 0.5, 1.0, 1.0) //name, material, radio ext, radio int, lenght

    man->SetTopVolume(top);

    top->AddNode(box, 0);
    top->AddNode(box, 1, trans_rot);
    top->AddNode(tube, 2);

    man->CloseGeometry();

    top->Draw("ogl")

    TPolyLine3D *l = new TPolyLine3D();
    l->SetLineColor(kRed);
    l->SetPoint(0, 0, 0, 0);
    l->SetPoint(1, 1, 1, 1);
    l->SetPoint(2, 0, 0, 2);
    l->Draw("same");
}
