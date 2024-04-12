int const N = 5e5 + 5;
int len[N];
// s este indexat de la 0
void failureFunction(string s)
{
  int j = 0, i = 1;
  while (i < s.size())
  {
    if (s[i] == s[j])
    {
      len[i++] = ++j;
    }
    else if (j == 0)
    {
      len[i++] = 0;
    }
    else
    {
      j = len[j - 1];
    }
  }
}
// Len[i] reprezinta lungimea celui mai lung prefix adecvat care este și sufix pentru s[0, i]
