
    {
        comp.assign(n, vector<int>(10, 0));
        int col = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ii cube = make_pair(i, j);
                if (valid(cube) && (!comp[i][j]))
                {
                    col++;
                    dfs(cube, col);
                }
            }
        }
        // what to remove
        vector<int> to_remove;
        int flag = 0;
        for (auto v : mp)
        {
            if (v.second >= k)
            {
                flag = 1;
                to_remove.push_back(v.first);
            }
        }
        if (!flag)
        {
            ulti_flag = 1;
        }
        // deletion
        if (flag)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    auto it = find(to_remove.begin(), to_remove.end(), comp[i][j]);

                    if (it != to_remove.end())
                    {
                        int k = i;
                        while (k > 0 && (g[k][j] != 0))
                        {
                            g[k][j] = g[k - 1][j];
                            k--;
                        }
                    }
                }
            }
        }
    }