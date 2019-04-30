// Example usage of the plotting template (originally used for TRG-17-001)
// Author: O. Davignon (CERN)
#include "PlotTemplate.C"

void ExampleUsage()
{
  // Example of how to use PlotTemplate.C

  // Modify the present script, then run using:
  // root -l
  // [0] .L ExampleUsage.C++
  // [1] ExampleUsage()

  TString PlotName = "myPlotName";
  bool LogY = true;
  bool DisplayGrid = true;
  TString Lumi = "35.9";

  TCanvas* myCanvas = CreateCanvas(PlotName, LogY, DisplayGrid);

  //here add the histos, functions, etc. you want to draw (drawing happens below)

  TF1* myFunction = new TF1("myFunction","x *100");
  // TF1* myFunction = new TF1("myFunction","x * ( exp(7.15226e-02 *2. / (2./52 - 0.0103 * x) + -2.73462e-01) + 9.90780e-01 * 2. / (2./52 - 0.0103 * x) + 7.22748e+00) + (1 - x) * ( exp(5.85573e-02 *2. / (2./52 - 0.0103 * x) + 4.54663e-02) + 1.22138e+00 * 2. / (2./52 - 0.0103 * x) + -4.79855e-01)");
  myFunction->SetTitle("");

  //or read file where histos are saved
  //TFile myFileContainingHistos("filename.root","READ");
  //myFunction = (TH1F*)myFileContainingHistos.Get("histoName");

  //follows are examples on how to format legends, axis, etc.

  //axis labels ranges & names
  double minimumX = 20.;
  double maximumX = 100.;
  double minimumY = 5.;
  double maximumY = 330.;
  if(LogY && minimumY==0.) cout<<"****** LogY == true and minimumY == 0, you probably want to avoid that ******"<<endl;
  myFunction->SetMinimum(minimumY);
  myFunction->SetMaximum(maximumY);
  myFunction->GetXaxis()->SetRangeUser(minimumX,maximumX);
  myFunction->GetYaxis()->SetTitle("y-axis title [unit]");
  myFunction->GetXaxis()->SetTitle("x-axis title [unit]");
  myFunction->GetXaxis()->SetTitleOffset(1.2);
  myFunction->GetYaxis()->SetTitleOffset(1.4);

  //line style  
  myFunction->SetLineColor(kBlue);
  myFunction->SetLineWidth(3);

  //drawing
  myFunction->Draw();

  //legend
  TLegend* leg = new TLegend(0.14,0.76,0.75,0.86);
  //leg->SetBorderSize(0);
  //leg->SetFillStyle(0);
  leg->SetTextSize(0.035);
  //leg->SetHeader("here is a beautiful header");
  leg->AddEntry(myFunction,"description of myFunction");
  leg->Draw("same");

  //line
  // double max_rate = 115.;
  // TLine* a115kHz_line = new TLine(0.,max_rate,1.,max_rate);
  // a115kHz_line->SetLineColor(kRed);
  // a115kHz_line->SetLineWidth(3.);
  // a115kHz_line->SetLineStyle(2);
  // a115kHz_line->Draw("same");

  DrawPrelimLabel(myCanvas);
  DrawLumiLabel(myCanvas, Lumi);
  SaveCanvas(myCanvas, PlotName);

  return;

}
