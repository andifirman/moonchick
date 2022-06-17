void parsingData(String dataTerima) {
  //    Convert from String Object to String.
  char buf[255];
  char *p = buf;
  char *str;
  char *data[6];
  int i;

  dataTerima.toCharArray(buf, sizeof(buf));
  while ((str = strtok_r(p, ";", &p)) != NULL) // delimiter is the semicolon
  {
    data[i] = str;
    i++;
  }

  String validasi = data[0];

  if (validasi == "B") {
    levelBlowerUDP = data[1];  
  }
  
}
