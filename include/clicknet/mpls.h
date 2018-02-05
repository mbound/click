#ifndef CLICKNET_MPLS_H
#define CLICKNET_MPLS_H

// MPLS header definition, Reference: RFC 5462, RFC 3032
//
//  0                   1                   2                   3
//  0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// |                Label                  | TC  |S|       TTL     |
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
//	Label:  Label Value, 20 bits
//	TC:     Traffic Class field, 3 bits
//	S:      Bottom of Stack, 1 bit
//	TTL:    Time to Live, 8 bits



#endif