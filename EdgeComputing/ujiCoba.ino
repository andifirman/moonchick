void ujiFixEdge() {
  String DBFixCoba = DBFixEdge + getDateGrafik() + "/" + getTime();
  String DBLangsungTemp = DBFixCoba + "/temp";
  String DBLangsungHumi = DBFixCoba + "/humi";
  String DBLangsungWind = DBFixCoba + "/wind";

  Firebase.setString(DBLangsungTemp,  String(sFixTemp));
  Firebase.setString(DBLangsungHumi,  String(sFixHumi));
  Firebase.setString(DBLangsungWind,  String(sFixWindSpeed));
}
