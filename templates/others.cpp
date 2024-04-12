mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

#ifdef ONPC
cerr << '\n'
     << "Program finished in" << clock() * 1.0 / CLOCKS_PER_SEC << "sec" << '\n';
#endif
