import unittest
import solution

class TestSolution(unittest.TestCase):
    def test_single(self):
        s = 'a'
        out = 1
        self.assertEqual(solution.solution(s), out)

    def test_all_same(self):
        s = 'aaaaaaaaaa'
        out = 10
        self.assertEqual(solution.solution(s), out)

    def test_all_diff(self):
        s = 'abcdefghijkl'
        out = 1
        self.assertEqual(solution.solution(s), out)

    def test_four_seqs_of_three(self):
        s = 'abcabcabcabc'
        out = 4
        self.assertEqual(solution.solution(s), out)
    
    def test_two_long_seq(self):
        s = 'abccbaabccba'
        out = 2
        self.assertEqual(solution.solution(s), out)
    
    def test_leftovers(self):
        s = 'abcdabcdabcdab'
        out = 1
        self.assertEqual(solution.solution(s), out)

    def test_seq_of_two(self):
        s = 'abababababababab'
        out = 8
        self.assertEqual(solution.solution(s), out)

    def test_palindrome(self):
        s = 'abcdeedcba'
        out = 1
        self.assertEqual(solution.solution(s), out)

if __name__ == '__main__':
    unittest.main()