// Older C++
// If there is no avatar, the Image pointer is NULL and has_avatar is false
// If there is an avatar, the Image pointer must be managed
// The bool must be synchronized with the Image pointer
class UserAccount {
    Image *avatar;                           // Users can have an optional "avatar"
    bool has_avatar;                         // Does this user have an avatar?
    // ...
};

// C++17
// Now, there is only one member corresponding to the avatar
// If there is no avatar, the optional member will be empty
// If there is an avatar, the optional member will contain an Image object
// This does not need to be a pointer to an Image
class UserAccount {
    std::optional<Image> avatar;             // Users can have an optional "avatar"
    // ...
};
