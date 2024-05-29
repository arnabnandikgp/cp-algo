{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        map<char,char> mp;
        for(int i=0;i<n-1;i++)
        {
            mp[s[i]] = '$';
        }
        // auto it = mp.begin();
 
        // Iterate through the map and print the elements
        // while (it != mp.end()) {
        // cout << "Key: " << it->first
        //      << ", Value: " << it->second << endl;
        // ++it;
        // }
        set<char> st(s.begin(),s.end());
         
        // for (auto mit = st.begin(); mit != 
        //                      st.end(); ++mit)
        // cout << ' ' << *mit;
        for(int i=0;i<n;i++)
        {
            if(i<st.size())
            {   
                auto it = st.find(s[i]);
                // if(it !=st.end())
                // {
                //     cout<<"meowwww"<<endl;
                // }
                int j = distance(st.begin(), it);
                // cout<<s[i]<<" j 1  "<<j<<endl;
                auto nit = s.rbegin();
                nit = prev(nit,-j);
                mp[s[i]]= *nit;
                cout<<s[i]<<" oye "<<mp[s[i]]<<