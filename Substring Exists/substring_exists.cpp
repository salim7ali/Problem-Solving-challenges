// Given two arrays of strings, determine whether corresponding elements contain a common substring

void commonSubstring(vector<string> a, vector<string> b){
    vector<bool> characters(26, 0);
    
    for(int i=0; i<a.size(); i++){
        characters.assign(characters.size(), false);
        string first = a[i];
        string second = b[i];
        for(int j=0; j<first.length(); j++)
            characters[first[j] - 'a'] = true;

        for(int j=0; j<second.length(); j++){
            if(characters[second[j] - 'a']){
                cout<<"YES\n";
                goto YES;
            }

        }
        cout<<"NO\n";
        YES:
            cout<<"";
    }
}