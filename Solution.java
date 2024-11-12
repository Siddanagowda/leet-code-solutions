public class Solution {
    public int[] maximumBeauty(int[][] items, int[] queries) {
        
        Arrays.sort(items, (a, b) -> Integer.compare(a[0], b[0]));

        int[][] indexedQueries = new int[queries.length][2];
        for (int i = 0; i < queries.length; i++) {
            indexedQueries[i][0] = queries[i];
            indexedQueries[i][1] = i;  
        }
        
        Arrays.sort(indexedQueries, (a, b) -> Integer.compare(a[0], b[0]));
        
        int maxBeauty = 0;
        int[] answer = new int[queries.length];
        int itemIndex = 0;

        for (int[] query : indexedQueries) {
            int priceLimit = query[0];
            int originalIndex = query[1];
            
            while (itemIndex < items.length && items[itemIndex][0] <= priceLimit) {
                maxBeauty = Math.max(maxBeauty, items[itemIndex][1]);
                itemIndex++;
            }
            
            answer[originalIndex] = maxBeauty;
        }
        
        return answer;
    }
}
