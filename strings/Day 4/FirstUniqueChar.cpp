/*
387. First Unique Character in a String     *EASY*

Given a string, find the first non-repeating character in it and return it's index.
If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool CheckKey(unordered_map<char, int> T, char key) {
    return !(T.find(key) == T.end());
}
int FirstUniqueChar(const string &s) {
    unordered_map<char, int> T{};
    for (int i(0); i < s.size(); ++i) {
        char c = s[i];
        if (CheckKey(T, c)) {
            T[c] += 1;
        }
        else {
            T.insert({c, 1});
        }
    }
    for (int i(0); i < s.size(); ++i) {
        if (T[s[i]] == 1) return i;
    }
    return -1;
}

int main() {
    string s = "leetcodel";
    string longe = "nvoekmkxihcwmpdfflrulnikjtllsxnfcbonxdapinkvmsfxodgeakmqgsshefgbcvlhpadvegcqkfxjphmsejjbdptdaptdvletslvsukqofijunitgaciuiuiwvuujbckiqeuvqbvaoclxsolxdvbsoqpblgqdakoxstrpjuqomfntfbuwwdmkucjtkercjsoxxidxortpxighosfsisinsewvtgnoveksqmewxrmdxuxmwhxmbdhcqfopnvfodpmvdfkevnemfxikukclrpxsxfiijxjdlttskvwqxldqqcjaqjgabermgefqvnrenawbvsatvfrpjncgtwdsimnbwkoqtpuskxobcwamqsfkojknmhilwvsjniiidwmvrgttdpvuxbaijmkntwxilrslwmwxtqhmtouhqxrksmtcspswjcwdaptaoxpofhgxwptexfshsceaxdcgulgefxopxskvjbjamkwskrrtwddbcxkqxbwsqidjalqdvixevvocqtofoxcgdkrkpeqwtecfjmjqdtcgpclucliocwxgqwbmoesqnksedlnnlriduxfhhrbvlimstkqpdbnhpsfwfsmsdecweomepfpdqfpbdwhdplbtpfbsxhfoflavvwhksxthcvimjkgxikofajharmbkiojqrgpcbhnkhbrtmomeahmvpxwjuaifnvpaximelvvmjpjfmktkxisswhifitkqciqfqtwxickmaixlbwbadobnustulnxkkxfwthvdbufkkvemmsxogcrwbojehownkkomquijvfwxbuijegfnaksmgnqitobomslwhsqbmtflvxcryckvxqmhcvqgivohpvlnrjwkxqcnefmvmhavnloqnitoelwqteqrnjhnvsfoqnenutnokkkhqmacjijabqabmlwsotnzrjdisicpmxglctophvwaixmvmvcidclmnqjgeexbnjlftuwieiwpiteppicxlpxqgcwimrtduiiuthqkslkosdpufvxigsjtdxsgkniwsepbdeeiruqfvghpmcjdeljfvxuaekesofolsdbaxnatjwsfgjapgkwnksfmupawqlodbuacwmejxcbbljlvlhrmfaffjeelqghrphrxwdtwnsujrrmeussjtrubebiihpjeuemhnrmtwgkvsljnalbfgokqmweomemvilbbfnaxxofwf";
    cout << FirstUniqueChar(longe);
}
