// Integer division with rounding down/up

llint div_floor(llint a, llint b) {
  if (b < 0) a = -a, b = -b;
  return a/b - (a%b < 0);
}

llint div_ceil(llint a, llint b) {
  if (b < 0) a = -a, b = -b;
  return a/b + (a%b > 0);
}
