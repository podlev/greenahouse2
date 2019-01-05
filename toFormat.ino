String toFormat(int value) {
  if (value < 10) {
    return '0' + String(value); 
  }
  else {
    return String(value);
  }
}
