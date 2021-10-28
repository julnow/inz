void pfRead(const char *fileName, const char *outputFileName){

  TFile* fileInPF = TFile::Open(fileName, "read");
  TTree* treeInPF = fileInPF->Get<TTree>("aTree");
  //simulated particles
  AnalysisTree::Chain* treeInSIM = new AnalysisTree::Chain(std::vector<std::string>({"fileslist.txt"}), std::vector<std::string>({"rTree"}));

  //setting headers type
  auto* can_header = new AnalysisTree::Particles();
  auto* simr_header = new AnalysisTree::Particles(); //reconstructed
  auto* can2simr_matching = new AnalysisTree::Matching();
  auto* sims_tracks = new AnalysisTree::Particles(); //simulation

  AnalysisTree::Configuration* config = fileInPF->Get<AnalysisTree::Configuration>("Configuration");
  //headers for branches
  treeInPF->SetBranchAddress("Candidates", &can_header);
  treeInPF->SetBranchAddress("Simulated", &simr_header);
  treeInPF->SetBranchAddress(config->GetMatchName("Candidates", "Simulated").c_str(), &can2simr_matching);
  treeInSIM->SetBranchAddress("SimParticles", &sims_tracks);

  //getting variables id
  //Candidates reconstructed
  const int canpx = config->GetBranchConfig("Candidates").GetFieldId("px");
  const int canpy = config->GetBranchConfig("Candidates").GetFieldId("py");
  const int canpz = config->GetBranchConfig("Candidates").GetFieldId("pz");
  const int canpt = config->GetBranchConfig("Candidates").GetFieldId("pT");
  const int canp = config->GetBranchConfig("Candidates").GetFieldId("p");
  const int chi2_geo = config->GetBranchConfig("Candidates").GetFieldId("chi2_geo");
  const int chi2_prim_first = config->GetBranchConfig("Candidates").GetFieldId("chi2_prim_first");
  const int chi2_prim_second = config->GetBranchConfig("Candidates").GetFieldId("chi2_prim_second");
  const int chi2_topo = config->GetBranchConfig("Candidates").GetFieldId("chi2_topo");
  const int canrap = config->GetBranchConfig("Candidates").GetFieldId("rapidity");
  const int canphi = config->GetBranchConfig("Candidates").GetFieldId("phi");
  const int cangen = config->GetBranchConfig("Candidates").GetFieldId("generation");
  //simulated reconstructed
  const int simrpx = config->GetBranchConfig("Simulated").GetFieldId("px");
  const int simrpy = config->GetBranchConfig("Simulated").GetFieldId("py");
  const int simrpz = config->GetBranchConfig("Simulated").GetFieldId("pz");
  const int simrpt = config->GetBranchConfig("Simulated").GetFieldId("pT");
  const int simrp = config->GetBranchConfig("Simulated").GetFieldId("p");
  //simulated Simulated
  const int simspx = treeInSIM->GetConfiguration()->GetBranchConfig("SimParticles").GetFieldId("px");
  const int simspy = treeInSIM->GetConfiguration()->GetBranchConfig("SimParticles").GetFieldId("py");
  const int simspz = treeInSIM->GetConfiguration()->GetBranchConfig("SimParticles").GetFieldId("pz");
  const int simspt = treeInSIM->GetConfiguration()->GetBranchConfig("SimParticles").GetFieldId("pT");
  const int simsp = treeInSIM->GetConfiguration()->GetBranchConfig("SimParticles").GetFieldId("p");
  const int simsrap = treeInSIM->GetConfiguration()->GetBranchConfig("SimParticles").GetFieldId("rapidity");
  const int simsphi = treeInSIM->GetConfiguration()->GetBranchConfig("SimParticles").GetFieldId("phi");
  const int simspid = treeInSIM->GetConfiguration()->GetBranchConfig("SimParticles").GetFieldId("pid");

  TFile* fileOut1 = TFile::Open(outputFileName, "recreate");
  //Candidates
  TH1F hcanpx("hcanpx", "candidate px;px [GeV/c];dN/dpx", 100, -3, 3);
  TH1F hcanpy("hcanpy", "candidate py;py [GeV/c];dN/dpy", 100, -3, 3);
  TH1F hcanpz("hcanpz", "candidate pz;pz [GeV/c];dN/dpz", 100, 0, 14);
  TH1F hcanpt("hcanpt", "candidate pt;pt [GeV/c];dN/dpt", 100, -1, 3);
  TH1F hcanp("hcanp", "candidate p;p [GeV/c];dN/dp", 100, 0, 14);
  TH1F hcanphi("hcanphi", "candidate #phi;#phi [rad];dN/d#phi", 100, -3.14, 3.14);
  //simulated
  TH1F hsimspx("hsimspx", "simulated px;px [GeV/c];dN/dpx", 100, -3, 3);
  TH1F hsimspy("hsimspy", "simulated py;py [GeV/c];dN/dpy", 100, -3, 3);
  TH1F hsimspz("hsimspz", "simulated pz;pz [GeV/c];dN/dpz", 100, 0, 14);
  TH1F hsimspt("hsimspt", "simulated pt;pt [GeV/c];dN/dpt", 100, -1, 3);
  TH1F hsimsp("hsimsp", "simulated p;p [GeV/c];dN/dp", 100, 0, 14);
  //difference
  TH1F hdifpx("hdifpx", "difference px;px [GeV/c];dN/dpx", 100, -.4, .4);
  TH1F hdifpy("hdifpy", "difference py;py [GeV/c];dN/dpy", 100, -.4, .4);
  TH1F hdifpz("hdifpz", "difference pz;pz [GeV/c];dN/dpz", 100, -.8, .8);
  TH1F hdifpt("hdifpt", "difference pt;pt [GeV/c];dN/dpt", 100, -.4, .4);
  TH1F hdifp("hdifp", "difference p;p [GeV/c];dN/dp", 100, -.8, .8);
  //correlations
  TH2F hcorpx("hcorpx", "correlations px; candidate; simulated", 100, -3, 3,  100, -3, 3);
  TH2F hcorpy("hcorpy", "correlations py; candidate; simulated", 100, -3, 3,  100, -3, 3);
  TH2F hcorpz("hcorpz", "correlations pz; candidate; simulated", 100, 0, 14,  100, 0, 14);
  TH2F hcorr_px_py("hcorr_px_py", "correlations rec px py; px; py", 100, -3, 3,  100, -3, 3);
  TH2F hcorpt("hcorpt", "correlations pt; candidate; simulated", 100, -1, 3,  100, -1, 3);
  TH2F hcorp("hcorp", "correlations p; candidate; simulated", 100, 0, 14,  100, 0, 14);
  TH2F hcorr_rap_pt("hcorr_rap_pt", "correlation rec rapidity pt; rapidity; pT", 100, -1, 4,  100, -1, 4);
  TH2F hcorr_phi_pt("hcorr_phi_pt", "correlation rec #phi pt; #phi; pT", 100, -5, 5,  100, -5, 5);
  //correlations for sim
  TH2F hcors_rap_pt("hcors_rap_pt", "correlation sim rapidity pt; rapidity; pT", 100, -1, 4,  100, -1, 4);
  TH2F hcors_phi_pt("hcors_phi_pt", "correlation sim #phi pt; #phi; pT", 100, -5, 5,  100, -5, 5);
  TH2F hcors_px_py("hcors_px_py", "correlations sim px py; px; py", 100, -3, 3,  100, -3, 3);
  //chi2
  TH1F hchi2_geo("chi2_geo", "chi2_geo", 100, -1, 6);
  TH1F hchi2_prim_first("chi2_prim_first", "chi2_prim_first", 100, -1, 300);
  TH1F hchi2_prim_second("chi2_prim_second", "chi2_prim_second", 100, -1, 300);
  TH1F hchi2_topo("chi2_topo", "chi2_topo", 100, -1, 10);


  //reading of data

  //simulation
  const int NeventsSIM = treeInSIM->GetEntries();
  for(int i=0; i<NeventsSIM; i++){
    treeInSIM -> GetEntry(i);
    //simulated simulated
    for(const auto& sim_track : *(sims_tracks->GetChannels()) ){
      if (sim_track.GetField<int>(simspid) == 3122){
        const float sims_px = sim_track.GetField<float>(simspx);
        const float sims_py = sim_track.GetField<float>(simspy);
        const float sims_pz = sim_track.GetField<float>(simspz);
        const float sims_pt = sim_track.GetField<float>(simspt);
        const float sims_p = sim_track.GetField<float>(simsp);
        const float sims_rap = sim_track.GetField<float>(simsrap);
        const float sims_phi = sim_track.GetField<float>(simsphi);
        hsimspx.Fill(sims_px);
        hsimspy.Fill(sims_py);
        hsimspz.Fill(sims_pz);
        hsimspt.Fill(sims_pt);
        hsimsp.Fill(sims_p);
        //correlations for simulated
        hcors_rap_pt.Fill(sims_rap, sims_pt);
        hcors_px_py.Fill(sims_px, sims_py);
        hcors_phi_pt.Fill(sims_phi, sims_pt);
      }
    }
  }

    //pfsimple
    const int NeventsPF = treeInPF->GetEntries();
    for(int i=0; i<NeventsPF; i++){
      treeInPF -> GetEntry(i);
    //candidates
    for (const auto& can_head : *can_header){
      //Candidates
      if (can_head.GetField<float>(cangen) == 0) continue; //only singal, not background (gen=0)
      const float can_px = can_head.GetField<float>(canpx);
      const float can_py = can_head.GetField<float>(canpy);
      const float can_pz = can_head.GetField<float>(canpz);
      const float can_pt = can_head.GetField<float>(canpt);
      const float can_p = can_head.GetField<float>(canp);
      const float can_rap = can_head.GetField<float>(canrap);
      const float can_phi = can_head.GetField<float>(canphi);

      hcanpx.Fill(can_px);
      hcanpy.Fill(can_py);
      hcanpz.Fill(can_pz);
      hcanpt.Fill(can_pt);
      hcanp.Fill(can_p);
      //correlation for reconstructed
      hcorr_rap_pt.Fill(can_rap, can_pt);
      hcorr_px_py.Fill(can_px, can_py);
      hcorr_phi_pt.Fill(can_phi, can_pt);
      //simulated
      const int simr_id = can2simr_matching->GetMatch(can_head.GetId());
      if(simr_id<0) continue;
      const float simr_px = simr_header->GetChannel(simr_id).GetField<float>(simrpx);
      const float simr_py = simr_header->GetChannel(simr_id).GetField<float>(simrpy);
      const float simr_pz = simr_header->GetChannel(simr_id).GetField<float>(simrpz);
      const float simr_pt = simr_header->GetChannel(simr_id).GetField<float>(simrpt);
      const float simr_p = simr_header->GetChannel(simr_id).GetField<float>(simrp);
      //differences
      hdifpx.Fill(can_px - simr_px);
      hdifpy.Fill(can_py - simr_py);
      hdifpz.Fill(can_pz - simr_pz);
      hdifpt.Fill(can_pt - simr_pt);
      hdifp.Fill(can_p - simr_p);
      //correlations
      hcorpx.Fill(can_px, simr_px);
      hcorpy.Fill(can_py, simr_py);
      hcorpz.Fill(can_pz, simr_pz);
      hcorpt.Fill(can_pt, simr_pt);
      hcorp.Fill(can_p, simr_p);
      //chi2
      const float can_chi2_geo = can_head.GetField<float>(chi2_geo);
      const float can_chi2_prim_first = can_head.GetField<float>(chi2_prim_first);
      const float can_chi2_prim_second = can_head.GetField<float>(chi2_prim_second);
      const float can_chi2_topo = can_head.GetField<float>(chi2_topo);
      hchi2_geo.Fill(can_chi2_geo);
      hchi2_prim_first.Fill(can_chi2_prim_first);
      hchi2_prim_second.Fill(can_chi2_prim_second);
      hchi2_topo.Fill(can_chi2_topo);

    }
  }
  //division of histograms
//  TH2F hcord_rap_pt("hcord_rap_pt", "division correlation rapidity pt; rapidity; pT", 100, -1, 4,  100, -1, 4);
//  TH2F hcord_phi_pt("hcord_rap_pt", "division correlation #phi pt; #phi; pT", 100, -5, 5,  100, -5, 5);
//  TH2F hcord_px_py("hcord_px_py", "division correlations px py; px; py", 100, -3, 3,  100, -3, 3);
//  hcord_rap_pt = (TH2F*) hcorr_rap_pt.Clone();
//  hcord_rap_pt->Divide(hcors_rap_pt);
//  hcord_phi_pt = (TH2F*) hcorr_phi_pt.Clone();
//  hcord_phi_pt->Divide(hcors_phi_pt);
//  hcord_px_py = (TH2F*) hcorr_px_py.Clone();
//  hcord_px_py->Divide(hcors_px_py);

  hcanpx.Write();
  hcanpy.Write();
  hcanpz.Write();
  hcanpt.Write();
  hcanp.Write();
  hsimspx.Write();
  hsimspy.Write();
  hsimspz.Write();
  hsimspt.Write();
  hsimsp.Write();
  hdifpx.Write();
  hdifpy.Write();
  hdifpz.Write();
  hdifpt.Write();
  hdifp.Write();
  hcorpx.Write();
  hcorpy.Write();
  hcorpz.Write();
  hcorpt.Write();
  hcorp.Write();
  hchi2_geo.Write();
  hchi2_prim_first.Write();
  hchi2_prim_second.Write();
  hchi2_topo.Write();
  hcorr_px_py.Write();
  hcorr_rap_pt.Write();
  hcorr_phi_pt.Write();
  hcors_px_py.Write();
  hcors_rap_pt.Write();
  hcors_phi_pt.Write();

  fileOut1->Close();
}
