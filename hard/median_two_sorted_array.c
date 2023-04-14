double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
  int numtotal = nums1Size + nums2Size;
  if (numtotal % 2 == 0) // even
  {
    int end = numtotal / 2;
    int p1 = 0, p2 = 0;
    int t = 0;
    int n1 = 0, n2 = 0;
    while (1)
    { 
      if (t == end+1)
      {
        return ((double)n1 + (double)n2) / 2;
      }
      else
      {
        if (p1 >= nums1Size)
        {
          n1 = n2;
          n2 = nums2[p2];
          p2++;
          t++;
        }
        else if (p2 >= nums2Size)
        {
          n1 = n2;
          n2 = nums1[p1];
          p1++;
          t++;
        }
        else
        {
          if (nums1[p1] <= nums2[p2])
          {
            n1 = n2;
            n2 = nums1[p1];
            p1++;
            t++;
          }
          else if (p1 < nums1Size && p2 < nums2Size)
          {
            n1 = n2;
            n2 = nums2[p2];
            p2++;
            t++;
          }
        }
      }
    }
  }
  else // odd
  {
    // return 0.0;

    int end = (numtotal + 1) / 2;
    int p1 = 0, p2 = 0;
    int t = 0;
    int n1 = 0, n2 = 0;
    while (1)
    {
      if (t == end)
      {
        return (double)n2;
      }
      else
      {
        if (p1 >= nums1Size && p2 < nums2Size)
        {
          n1 = n2;
          n2 = nums2[p2];
          p2++;
          t++;
        }
        else if (p2 >= nums2Size && p1 < nums1Size)
        {
          n1 = n2;
          n2 = nums1[p1];
          p1++;
          t++;
        }
        else if (p1 < nums1Size && p2 < nums2Size)
        {
          if (nums1[p1] <= nums2[p2])
          {
            n1 = n2;
            n2 = nums1[p1];
            p1++;
            t++;
          }
          else
          {
            n1 = n2;
            n2 = nums2[p2];
            p2++;
            t++;
          }
        }
      }
    }
  }
}