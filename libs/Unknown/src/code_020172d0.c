#include "code_020172d0.h"
#include "code_0201750c.h"

// Adds object at the end of list; an empty list gets it as its only object.
void NNS_FndAppendListObject(NNSFndList *list, void *object) {
    NNSFndLink *links;

    if (list->mHead == 0) {
        SetFirstObject(list, object);
        return;
    }
    links = (NNSFndLink *) ((u8 *) object + list->mLinkOffset);
    links->mPrevObject = list->mTail;
    links->mNextObject = 0;
    ((NNSFndLink *) ((u8 *) list->mTail + list->mLinkOffset))->mNextObject = object;
    list->mTail = object;
    list->mCount++;
}

// Adds object at the start of list; an empty list gets it as its only object.
void NNS_FndPrependListObject(NNSFndList *list, void *object) {
    NNSFndLink *links;

    if (list->mHead == 0) {
        SetFirstObject(list, object);
        return;
    }
    links = (NNSFndLink *) ((u8 *) object + list->mLinkOffset);
    links->mPrevObject = 0;
    links->mNextObject = list->mHead;
    ((NNSFndLink *) ((u8 *) list->mHead + list->mLinkOffset))->mPrevObject = object;
    list->mHead = object;
    list->mCount++;
}

// Puts object in front of target; a NULL target appends it at the end.
void NNS_FndInsertListObject(NNSFndList *list, void *target, void *object) {
    u32 linkOffset;
    NNSFndLink *links;
    void *prevElement;

    if (target == 0) {
        NNS_FndAppendListObject(list, object);
        return;
    }
    if (target == list->mHead) {
        NNS_FndPrependListObject(list, object);
        return;
    }
    linkOffset = list->mLinkOffset;
    links = (NNSFndLink *) ((u8 *) object + linkOffset);
    prevElement = ((NNSFndLink *) ((u8 *) target + linkOffset))->mPrevObject;
    links->mPrevObject = prevElement;
    links->mNextObject = target;
    ((NNSFndLink *) ((u8 *) prevElement + linkOffset))->mNextObject = object;
    ((NNSFndLink *) ((u8 *) target + list->mLinkOffset))->mPrevObject = object;
    list->mCount++;
}

// Unlinks object from list and clears its links.
void NNS_FndRemoveListObject(NNSFndList *list, void *object) {
    NNSFndLink *links;
    void *neighbor;

    links = (NNSFndLink *) ((u8 *) object + list->mLinkOffset);
    neighbor = links->mPrevObject;
    if (neighbor == 0) {
        list->mHead = links->mNextObject;
    } else {
        ((NNSFndLink *) ((u8 *) neighbor + list->mLinkOffset))->mNextObject = links->mNextObject;
    }
    neighbor = links->mNextObject;
    if (neighbor == 0) {
        list->mTail = links->mPrevObject;
    } else {
        ((NNSFndLink *) ((u8 *) neighbor + list->mLinkOffset))->mPrevObject = links->mPrevObject;
    }
    links->mPrevObject = 0;
    links->mNextObject = 0;
    list->mCount--;
}

// Returns the element after object, or the first element when object is NULL.
void *NNS_FndGetNextListObject(NNSFndList *list, void *object) {
    if (object == 0) {
        return list->mHead;
    }
    return ((NNSFndLink *) ((u8 *) object + list->mLinkOffset))->mNextObject;
}

// Returns the element before object, or the last element when object is NULL.
void *NNS_FndGetPrevListObject(NNSFndList *list, void *object) {
    if (object == 0) {
        return list->mTail;
    }
    return ((NNSFndLink *) ((u8 *) object + list->mLinkOffset))->mPrevObject;
}

// Returns the element at position index counted from the start of list, or NULL.
void *NNS_FndGetNthListObject(NNSFndList *list, u16 index) {
    s32 seen;
    void *element;

    seen = 0;
    element = NNS_FndGetNextListObject(list, 0);
    while (element != 0) {
        if (seen == index) {
            return element;
        }
        seen++;
        element = NNS_FndGetNextListObject(list, element);
    }
    return 0;
}

s32 func_020172d0(s32 a) {
    return a << 4;
}
