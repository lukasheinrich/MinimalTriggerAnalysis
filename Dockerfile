FROM lukasheinrich/atlas-athanalysisbase-2.4.8
ADD . /analysis/MinimalTriggerAnalysis
WORKDIR /analysis
RUN source $AtlasSetup/scripts/asetup.sh AthAnalysisBase,2.4.8,here && cmt find_packages && cmt compile
