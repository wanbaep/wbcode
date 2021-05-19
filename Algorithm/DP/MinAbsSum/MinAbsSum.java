import java.util.*;

class MinAbsSum {
    public static void main(String[] args) {
        Solution solution = new Solution();
        int minAbsSum = solution.solution(new int[] {3, 3, 3, 4, 5});
        System.out.println(minAbsSum);
    }
}

class Solution {
    public int solution(int[] A) {
        if(A.length == 0) return 0;
        int[] absA = getAbsArray(A);
        Map<Integer, Integer> countMap = getNumberCount(absA);
        int sum = getSum(absA);
        int[] subSum = new int[sum];

        Arrays.fill(subSum, -1);
        subSum[0] = 0;
        for(int key : countMap.keySet()) {
            for(int i = 0; i < sum/2 + 1; i++) {
                if(subSum[i] >= 0) {
                    subSum[i] = countMap.get(key);
                } else if(i >= key && subSum[i - key] > 0) {
                    subSum[i] = subSum[i - key] - 1;
                }
            }
        }

        int result = sum;
        for(int i = 0; i < sum; i++) {
            if(subSum[i] >= 0) {
                result = Math.min(result, sum - 2 * i);
            }
        }

        return result;
    }

    public int[] getAbsArray(int[] A) {
        int[] absA = new int[A.length];
        for(int i = 0; i < A.length; i++) {
            absA[i] = Math.abs(A[i]);
        }
        return absA;
    }

    public Map<Integer, Integer> getNumberCount(int[] A) {
        Map<Integer,Integer> countMap = new HashMap<>();
        for(int value : A) {
            countMap.put(value, countMap.getOrDefault(value, 0) + 1);
        }
        return countMap;
    }
    public int getSum(int[] A) {
        int sum = 0;
        for (int a : A) {
            sum += a;
        }
        return sum;
    }
}