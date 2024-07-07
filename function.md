# Functionalities, Analysis and Code

## Functionalities Identified:

### 1. **Most liked/disliked song**
 
### 2. **Music Playback and Live Radio Streaming**

### 3. **Playlist Management**
        
### 4. **History of Songs**

### 5. **Content Delivery Optimization**
   
### 6. **Ad Insertion during streaming**

### 7. **Searching with Autocomplete feature**

### 8. **Content Indexing and Retrieval from Memory**
    
### 9. **Shuffling of Songs**

### 10. **Payment Subscription**


## Analysis and Code

### 1. **Most liked/disliked song**:
#### Initial Implementation Using Arrays

Arrays can be used to store like/dislike counts, with each index representing a song and its value representing the count.

**Drawbacks:**

- **Time Complexity:**
  - **Update Operation:** `O(1)` for updating a single like/dislike count.
  - **Query Operation:** `O(N)` for finding the highest/lowest like/dislike count, where `N` is the number of songs.

- **Space Complexity:** `O(N)` for storing like/dislike counts.

While updating counts is efficient, querying the highest or lowest like/dislike count requires scanning the entire array, which is inefficient for large datasets.

#### Optimized Implementation Using Segment Trees and Fenwick Trees

- **Segment Trees:** Allow efficient handling of range queries and updates.
- **Fenwick Trees:** Efficiently manage cumulative frequency tables, allowing for quick updates and prefix sum queries.

**Implementation:**

1. **Segment Tree Construction:** Build a segment tree from the like/dislike counts array.
2. **Fenwick Tree Construction:** Build a Fenwick tree from the like/dislike counts array.
3. **Update Operation:** 
   - Update the like/dislike count in the segment tree.
   - Update the like/dislike count in the Fenwick tree.
4. **Query Operation for Segment Tree:** Query the segment tree for the highest/lowest like/dislike count in a range.
5. **Query Operation for Fenwick Tree:** Query the prefix sum in the Fenwick tree for cumulative likes/dislikes up to a certain index.

**Complexity Analysis:**

- **Time Complexity:**
  - **Update Operation (Both):** `O(log N)`
  - **Query Operation (Both):** `O(log N)`
  
- **Space Complexity:**
  - `O(4N)` for storing the segment tree.
  - `O(N)` for storing the Fenwick tree.

Both Segment Trees and Fenwick Trees significantly enhance the efficiency of the like/dislike system in a music streaming application. These data structures reduce the time complexity of update and query operations from `O(N)` to `O(log N)`, providing a more scalable and responsive solution compared to arrays. This ensures better performance and a superior user experience, especially with a large number of songs.


