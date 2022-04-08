struct Number long_Division(struct Number X, struct Number Y,ll precision)
{
  ll a_val = X.power;
  ll b_val = Y.power;
  ll kk = precision;
  while(kk--) X.num.push_back(0);
  ll power = a_val - b_val;
  reverse(X.num.begin(), X.num.end());
  reverse(Y.num.begin(), Y.num.end());
  ll k = X.num.size();
  ll l = Y.num.size();
  vector<int> r(k + 1);
  vector<int> q(k - l + 1);
  for (ll i = 0; i < k; i++)
  {
    r[i] = X.num[i];
  }
  r[k] = 0;
  for (ll i = (k - l); i >= 0; i--)
  {
    q[i] = floor((float)(((r[i + l] * base) + r[i + l - 1]) / (Y.num[l - 1])));
    if (q[i] >= base)
    {
      q[i] = base - 1;
    }
    int cry = 0;
    for (ll j = 0; j <= (l - 1); j++)
    {
      int tmp = r[i + j] - (q[i] * Y.num[j]) + cry;
      if (tmp < 0)
      {
        if (tmp % base == 0)
        {
          cry = tmp / base;
          r[i + j] = 0;
        }
        else
        {
          cry = -(abs(tmp) / base + 1);
          r[i + j] = (abs(tmp) / base + 1) * (base)-abs(tmp);
        }
      }
      else
      {
        cry = tmp / base;
        r[i + j] = tmp % base;
      }
    }
    r[i + l] += cry;
    while (r[i + l] < 0)
    {
      cry = 0;
      for (ll j = 0; j <= (l - 1); j++)
      {
        ll tmp = r[i + j] + Y.num[j] + cry;
        if (tmp < 0)
        {
          if (tmp % base == 0)
          {
            cry = tmp / base;
            r[i + j] = 0;
          }
          else
          {
            cry = -(abs(tmp) / base + 1);
            r[i + j] = (abs(tmp) / base + 1) * (base)-abs(tmp);
          }
        }
        else
        {
          cry = tmp / base;
          r[i + j] = tmp % base;
        }
      }
      r[i + l] += cry;
      q[i] = q[i] - 1;
    }
  }
  reverse(q.begin(), q.end());
  struct Number ans;
  ans.num = q;
  ans.power = power-precision;
  return ans;
}