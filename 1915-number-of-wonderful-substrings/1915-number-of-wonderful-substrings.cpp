class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long result = 0;
        unordered_map<int, int> hmap;
        int bits = 0;
        hmap[0] = 1;
        for (char ch : word) {
            int idx = (ch - 'a');
            bits = bits ^ (1 << idx);
			// all evens
            if (hmap.find(bits) != hmap.end()) {
                result += hmap[bits];
            }
			// iterate on the only one odd for each char
            for (int i = 0; i < 10; i++) {
                int bits2 = bits ^ (1 << i);
                if (hmap.find(bits2) != hmap.end()) {
                    result += hmap[bits2];
                }
            }
            hmap[bits]++;
        }
        return result;
    }
};