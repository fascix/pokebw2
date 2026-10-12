#ifndef POKEBW2_SAVE_SHORTCUT_H
#define POKEBW2_SAVE_SHORTCUT_H

#include "types.h"
#include "struct_decls.h"

// The registered shortcuts, 0xff when a slot is empty
struct ShortcutSave {
    u8 ids[0x24];
}; // size: 0x24

void ShortcutSave_Init(ShortcutSave *shortcutSave);
ShortcutSave *SaveControl_GetShortcutSave(SaveControl *save);
// The same block, which SaveControl_GetShortcutSave returns through it
ShortcutSave *SaveControl_GetShortcutSaveCore(SaveControl *save);
u32 ShortcutSave_GetShortcutCount(ShortcutSave *shortcutSave);
u8 ShortcutSave_GetRegistItem(ShortcutSave *shortcutSave, u8 index);
// Replaces shortcut 7 (DNA Splicers that fuse) with 8 (that separate), or 8 with 7
void func_0200cc34(ShortcutSave *shortcutSave, u32 shortcut);
// Takes the shortcut item out and puts it back at index, or in the first free slot for 0xff, and returns where it ended up
u32 ShortcutSave_MoveItemToIndex(ShortcutSave *shortcutSave, u32 item, u32 index);

#endif // POKEBW2_SAVE_SHORTCUT_H
