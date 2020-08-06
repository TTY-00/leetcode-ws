#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    int is_palin(string s){
        int left = 0;
        int right = s.length() - 1;
        int res;

        while(right > left){
            if(s[left++] != s[right--]) return false;
        }

        return true;
    }

    vector< vector<int> > palindromePairs(vector<string>& words) {
        vector< vector<int> > res;

        for(int i = 0; i < words.size(); i++){
            for(int j = i + 1; j < words.size(); j++){
                string s1 = words[i] + words[j];

                // cout << s1 << " " << endl;
                // cout << is_palin(s1) << endl;


                if(is_palin(s1)){
                    int ress_l[2] = {i, j};
                    vector<int> ress(ress_l, ress_l + 2);

                    res.push_back(ress);
                }

                string s2 = words[j] + words[i];

                // cout << s2 << " " << endl;
                // cout << is_palin(s2) << endl;


                if(is_palin(s2)){
                    int ress_l[2] = {j, i};
                    vector<int> ress(ress_l, ress_l + 2);

                    res.push_back(ress);
                }
            }
        }
        return res;
    }
};

int main(){
    // string words_l[5] = {"abcd","dcba","lls","s","sssll"};
    // string words_l[2] = {"a", "a"};
    // string words_l[3] = {"bat","taeb","caet"};
    string words_l[460] = {"abbhjdgibebcedeifff","dfbffjfbggeacbjeh","ebjjbehbbicfje","bffiehjd","gcgjjffchejijabf","igdiijafaga","aebebagj","jhefcajdh","af","hibdhafdjfahagb","gbjedgfh","daeihijbfd","gbi","j","acdggdjieh","fedf","agcfdgjgg","cjcbaiabgaajcjjc","bedggafahd","jidacea","gf","giifdfgjaagiaac","ihgfbgdgeie","edeebhhjdg","gchgbbaiagdi","iajiajifcjbg","afichcaghdcic","jddccfjhbeffh","dfdac","acacijjefajjjdgajd","ghhcaibfgafdcfbdaidh","hfcfhchbgfeccjihg","fgdacadei","bcihd","i","bjbiiajdagjgcceeehag","chchjfd","fdejajdcca","eiacfcgdbbebj","hfaedgijaaejdgbcffa","febh","fg","jdefa","dehgbijdedccfjiihc","gjjfigdc","dhgiebejjifbhedae","jibfheceejdfe","jfefhjhccghbjb","iiacjeeafjhiie","hbjbebcagbgjdicch","eiebhffccbdjfe","ifice","gehaagih","jhcjhaididbhhccj","eegea","iibc","hbfec","iajedcehgbbjihda","eiid","gdigcjjjfcd","e","gagdggajdaefdc","fgjhcajfd","ajagc","acjbbhfjf","abhjfchgfiajbaedbf","ghajfhafd","iccjihdbbadgcjgihg","ececgiej","beha","hedegbh","bfbcbcjjbddcgieebb","hbiebgabggeeic","ahaj","cebhcecbcdfcgabi","hjeeeibhfa","cgcja","hebefgifddgcdhabh","b","jhdhdebecbhjg","gaid","biehhcgiegag","aj","ijddecjaegbihbaiifc","ageibacjebd","hhagcdcb","hccgicbabcgda","d","eg","fgbceadebcd","fcbabghagfh","dhciddcbfjdc","dgdihbbecgbhhgjiec","fca","bdbe","fefcegifc","accdgbcaagb","eeegcjjcghiffdafeife","jbajdfhbgca","ddacfffgghch","accageddb","hhefbaacaaiadbhcgi","hjchgaeijj","bfjcdjgggeagbgg","jf","hffjicfhjh","da","hff","dgjfehfhhffbcdi","haahciife","df","eafdcied","ifggbgjfdi","gdjfhddabbh","fdfcebgihf","cahcdhjejfadbjej","icehedejfbgjdhi","jjbafcehcfi","icebecfbgfccb","chdhdjfbfhdhachhfbh","fbdiijiabjcbjeda","becbjahaj","iefjfecdjbicghgae","iddhjac","cddhghgagfhhhb","icdg","cjccbjjhjeceje","bfdggba","jicdjigahigfad","dbjdijhihcecajge","gdffdbd","hcjjcgdgjagd","ciheggbafehajebijbhd","hedhgdgajha","ccjecbeda","hd","adjdjhfeigfecgachbg","cjiacadhabje","cadaajhbbaehf","gdaiefaicieaghiggci","ah","hbbahge","ijjgadjhjdebihcagd","jhacciibiebcfhbcje","ahgabjhgiieaeffdf","a","bbjggaddbabfdabbehgg","egdfj","cjihacibheiifdafbij","jeaaehbaffddahfa","g","c","gicd","agaa","ggjhef","fdhfjfdbefadcgbbbfa","jcigchfab","jjeecha","ejighedehbcdhgccdijj","gddec","idefajbjcj","bejcfjaci","dbfajifbdihigfijcje","aefdghifcgidhghdh","gjfejgcefeihhdcha","gaggidbefjccfiibj","habd","caahcdbaeifjbcjj","ia","cacfegbadacgechbc","adjdcidccgjbaajcijaa","jbeccehdcgbda","idgbicgff","hdcgfaehcfbge","icgbfgf","ggigcdabfcdfghdf","jfibigea","dihfgidegjebb","jfbbgdddci","bdee","cce","gegbcidh","fahiicfjccfijghdag","dhafjjbceeaeb","ab","db","hgacbdebhjhiieeiech","gebh","dcaficjegji","ehibeja","hfhaacgfedigijjf","hhcdaffgjfddigj","hahjihhehgh","ccfeedj","hdgaehfbdj","efcfdiifghjcba","ajfheehdgdaeedbccih","dffbeefjfidjjai","cfefjece","faacdfhjgffbiighe","gb","ffhbebb","fgh","eaah","bejffcihgdbbbjgead","jhicbcfebjdaj","eghgcjejbfjeafjbeji","cechggeijfbbfdiagej","gbigdaegf","ihbbjbgd","jhaabigggdae","eibbbbgchcafggiafbei","jaeedjagcfidicbbbj","agehfdihabcechbj","hadcbe","bjedaeb","ihdjedh","ihcgia","hbajijeaji","gigecdcbgdhe","icgj","jbecdjbebfeffigi","ieidfbgg","iihidcbjehg","hh","djcagcfhbccgcjca","jda","dbheifjiicjgcegfga","fabgabdjga","ddehdcgibefdf","chehf","dcaajae","bbffbababfecfeabf","iciegcdfjdebggh","ibdeijhafj","dfaheddjiabjeheib","hggcigiaejcbd","fjdijfhfbfjhf","gffhfahbgjjgc","fih","bahiciia","edf","ifbb","jfdfj","eajjgfa","jcg","eghcdgf","edhhhaijgaeddcc","eee","jbea","h","djhjdbbbehggddbc","fibhegigfijde","bgffbfgeh","ebabhbhhiadd","dahchcehdhcj","ghjah","ehcajchjaigijeebfhg","chfbaicaha","dcd","gdehjhfechcaecei","jbegfcefe","fbeahjdgdhe","aehie","jhbbachejgi","fgaccbgcjega","bbihhejdhbddhhjgaah","bjibfhdjbd","iibiijdejcaigeggdabi","igbjgighccbhj","bgbceeffgbegicg","gajfeafadfbig","hcibiajcecaih","djj","ae","bcgfjbach","geijaca","fghfhcgfedccachjj","hjiifhf","efd","gi","gcebi","ceeibgcd","caeiaiabdiaiccfae","gfcgcedd","fijcdaijfjaaggcef","fjfe","chcdjhdbheci","jjgcbgc","jjiajjfbb","iihhfhchjffejcahiah","ee","chdjahadfhhifag","gbgg","cgfifaiccbffihfff","abddfjggha","effja","ag","ebehidh","cdiidigdfjhjfgif","abjabjccejjdfieh","abahcgjjac","cjfgahjdf","cgeehgfihccehe","bfifcbbhd","dfdbggfbicbhhcgf","bfa","gfiggaej","jibcbfbcha","jbihgdeejfchhgcbd","deddaccdj","dgfagibaeicdfe","hdeeidbccfjaa","bcajhacba","adhcbijgjcaiibg","jfhdhjiaia","iajdhbjhbaegefii","iabcjhfdeca","eifihcibcifb","ecdgdjd","gjjhfe","djadebbij","bieeaicg","aeheedjhcefgbcgjcija","cahgejjjij","fh","bdddfbafgaibac","cbgdchcafdbcfegihfe","ija","hdeiigefeddb","gjjacadfdi","cgaafd","fdeadibajabeaedjaaf","ejjfec","gcbfb","jeacccaiifejbaedj","hebebhhb","hhadhjbf","hbdjdecfja","eicagdfihfhiebgdadc","ejacjcddbibgjj","gdehbfc","hdcdhcdibi","jfhbaijfejiibjjae","jbgahebiei","jfbhfhi","dhfeegjdjfdghehiifj","ebcjgcfgffb","fjiedjchabgcbbeg","djfeddcaaec","giahad","fhjadjjfdbehhhbcjde","ecegdcchfjbhafia","jdb","bbdddehbgi","abccddaged","ibfci","fhefbjbgfcidddjebf","hdcfajeacccfjia","jgicjehhahihhj","edajfg","bb","ga","fcajh","faijghiggicd","bjhfbfcad","gcjcbhfdfhihcbbbbhf","bjj","cgegcgaffcjcbdabdjbi","idjhb","gfgcdeccb","jjidihaiahehba","fb","adfecchdiafijj","dfbefbfbjf","hiehggaaaa","ebejjhif","cidcaeaiijbfchhd","eeajebbchh","ejffjhfjffae","dijihheagcdefjhaf","ffghcafbcegdcbfjjid","hgeaafgfahidhdfcg","iedfebbfiehceda","bjgdgdjighadahhaie","fjh","adhdfaaecjihe","dbdcaffaigech","cfhieebiiijgjjhgdgd","ddbbhihbh","cf","gidfgdigafhbdhdai","ehdfafjfcbidjbcad","ejffiihaaaicbabdhf","dhehc","cjefjggiafigffcbj","hjfdda","jfabbbi","gbjddbjhefici","ddifiaijdjbfaj","gee","iie","haedhehabaddedjecgc","cbiifeefggcideiia","hieadgiia","ejcjajidhaebbgch","ababejhjdjfciefhi","hhacadigei","cgbbiee","eebfgcgje","cfiefddijgaadffgfihe","iebbbbehhiijhiii","hfhhjihfd","fegagieeaeefde","f","fbbcgbec","ffgiccahcejdggbe","djjfghai","eejeccifhcj","ebcjb","baaccgbffcbfcfbi","hfeeacbdchif","jigfifef","jdeggbd","icfcicicbiggjdhjaij","fhbebfi","icafbbigddhhg","ijgjjiehcfhg","jgbcaijiagd","hcf","hffhjaebaibbag","cjcgcejcgdhh","ibaheiegbjegdgjfgf","eiedcebhigiiicdb","behjjehbecbg","fddjggajia","gjbbfa","hedbjjg","ijjahibhbagfddbjjj","igbcfgjb","cchai","id","jidegeaeieddcggedbde","eghjdjceh","dichgjefjggjhjc","ifefdicgj","hgieiaga","jbbhhbdgi","didghhcfccgfjbibb","eibhadgjgiigedfg","jfaci","aajdegffggici","hgccdbeabicacfcfaj","gcghbaibihf","edcggh","chijaecfdaj","chcdfdgddahdhf","cfafhigjdifhiiigdi","gdgdbadehdcjejgdgae","hhihchibdjea"};
    vector<string> words(words_l, words_l + 460);

    Solution sol;
    vector< vector<int> >  res = sol.palindromePairs(words);
    for(int i = 0; i < res.size(); i++){
        cout << "[*] " << words_l[res[i][0]] + words_l[res[i][1]] << endl;
    }
    
    return 0;
}

class Solution {
public:
     bool f(string& s,int left,int right){
        while(left < right){
            if(s[left++] != s[right--]) return false;//判断是否是回文对
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        //string test = "abcdef";
        //cout << test.substr(3) << endl;
        unordered_map<string,int> words_index_map;
        set<int> word_size_set;
        int n = words.size();
        for(int i=0;i<n;i++){
            words_index_map[words[i]]=i;//每个单词桶的value是索引
            word_size_set.insert(words[i].size());//记录每个单词串长度
        }
        vector<vector<int>> res;
        for(int i=0; i < words.size(); i++){
            string word_reverse = words[i];
            reverse(word_reverse.begin(), word_reverse.end());//反转每个单词
            //如果reverse的字符在map中存在且不是自身，那么相加肯定是个回文对
            if(words_index_map.count(word_reverse) && words_index_map[word_reverse] != i){
                res.push_back({words_index_map[word_reverse], i});//返回两个单词对应索引
            }
            int length = word_reverse.size();

            for(auto it = word_size_set.begin(); *it != length; it++){
                int d = *it;
                //遍历是否存在word前/后部分回文，以及剩余部分在map中是否存在，注意word已经是反转后的，map是没有反转的
                //XXXXXabc,cba
                //abcXXXXX,cba
                if(f(word_reverse, 0, length - d - 1) && 
                    words_index_map.count(word_reverse.substr(length - d))){//substr表示索引从length-d开始到结束间的字符
                    res.push_back({i, words_index_map[word_reverse.substr(length - d)]});
                }
                if(f(word_reverse, d, length - 1) && 
                    words_index_map.count(word_reverse.substr(0, d))){
                    res.push_back({words_index_map[word_reverse.substr(0, d)], i});
                }
            }
            
        }
        return res;
    }
};