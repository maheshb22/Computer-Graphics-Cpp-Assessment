/* Rectangle Intersection 
In order to check if two rectangles intersect, we need to compare their boundaries. 
For example: take two rectangles A and B with coordinates left, right, top, bottom.There are 4 cases we can find
1.If rectangle A is above the rectangle B
2.If rectangle A is below the rectangle B
3.If rectangle A is to the left of the rectangle B
4.If rectangle A is to the right of the rectangle B
 
for first case: if A.top < B.bottom return false;
for second case: if A.bottom > B.top return false;
for third case: if A.right < B.left return false;
for fourth case: if A.left > B.right return false;
Otherwise return true;
The code for to check the two rectangles intersect or not is witten below Psuedocode*/
struct Rectangle {
    float l;
    float r;
    float t;
    float b;
};

void is_intersect(Rectangle A, Rectangle B) {
    if (A.t < B.b) {
        return false;
    }
    if (A.b > B.t) {
        return false; 
    }
    if (A.r < B.l) {
        return false;
    }
    if (A.l > B.r) {
        return false; 
    }
    return true;
}

// First I thought of writing code or logic to check if two rectangles intersect each other when they overlap but building this logic takes a time and confusing logics and unnessary code.So worked with the pen and paper to find easier way to code it.