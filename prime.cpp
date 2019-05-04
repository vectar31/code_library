// Compute prime numbers up to MAX
//
// To initialize, call init_prime().
// This will compute all primes lower than or equal to MAX.
//
// Globals:
// - prime[x] is true iff x is prime
// - P contains all primes up to MAX
//
// Time complexity: O(N log log N)
//
// Constants to configure:
// - MAX is the upper bound (exclusive) on primes to compute

bool prime[MAX];
vector<int> P;

void init_prime() {
  prime[2] = true;
  for (int i = 3; i < MAX; i += 2) prime[i] = true;

  for (int i = 3; i*i < MAX; i += 2)
    if (prime[i])
      for (int j = i*i; j < MAX; j += i+i)
        prime[j] = false;

  REP(i, MAX) if (prime[i]) P.push_back(i);
}
