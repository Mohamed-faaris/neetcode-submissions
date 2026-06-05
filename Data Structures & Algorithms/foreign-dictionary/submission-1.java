class Solution {
  public String foreignDictionary(String[] words) {
    HashMap<Character, int[]> map = new HashMap();
    int[] indegree = new int[26];

    for (String word : words) {
      for (char c : word.toCharArray()) {
        map.putIfAbsent(c, new int[26]);
      }
    }

    for (int i = 1; i < words.length; i++) {
      int minLength = Math.min(words[i].length(), words[i - 1].length());
      for (int j = 0; j < minLength; j++) {
        if (words[i - 1].length() > words[i].length() && words[i - 1].startsWith(words[i])) {
          return "";
        }
        if (words[i].charAt(j) != words[i - 1].charAt(j)) {
          char current = words[i - 1].charAt(j);
          char next = words[i].charAt(j);

          if (map.get(current)[next - 'a'] == 0) {
            map.get(current)[next - 'a'] = 1;
            indegree[next - 'a']++;
          }
          break;
        }
      }
    }

    // debug
    {
      System.out.print("  ");
      for (char ch = 'a'; ch <= 'z'; ch++) {
        System.out.print(ch + " ");
      }
      System.out.println();

      map.forEach((k, v) -> {
        System.out.print(k + " ");
        for (int num : v) {
          System.out.print(num + " ");
        }
        System.out.print(indegree[k - 'a']);
        System.out.println();
      });
    } // debug end

    String s = "";
    int i = 0;
    for (char c : map.keySet()) {
      if (indegree[c - 'a'] == 0)
        s += c;
    }
    while (i < s.length()) {
      int[] adj = map.get(s.charAt(i));
      for (int k = 0; k < 26; k++) {
        if (adj[k] == 1) {
          indegree[k] -= 1;
          if (indegree[k] == 0) {
            s += (char) ('a' + k);
          }
        }
      }
      i++;
    }
    if (s.length() != map.size()) {
      return "";
    }
    return s;
  }
}
