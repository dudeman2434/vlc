/*****************************************************************************
 * vlc_playlist.h : Playlist functions
 *****************************************************************************
 * Copyright (C) 1999, 2000, 2001, 2002 VideoLAN
 * $Id: vlc_playlist.h,v 1.6 2002/12/03 23:36:41 gitan Exp $
 *
 * Authors: Samuel Hocevar <sam@zoy.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111, USA.
 *****************************************************************************/

/*****************************************************************************
 * playlist_item_t: playlist item
 *****************************************************************************/
struct playlist_item_t
{
    char *     psz_name;
    char *     psz_uri; 
    int        i_type;   /* unused yet */
    int        i_status; /* unused yet */
    vlc_bool_t b_autodeletion;
};

/*****************************************************************************
 * playlist_t: playlist structure
 *****************************************************************************
 * The structure contains information about the size and browsing mode of
 * the playlist, a change lock, a dynamic array of playlist items, and a
 * current item which is an exact copy of one of the array members.
 *****************************************************************************/
struct playlist_t
{
    VLC_COMMON_MEMBERS

    int                   i_index;                          /* current index */
    int                   i_status;
    int                   i_size;                              /* total size */

    playlist_item_t **    pp_items;

    input_thread_t *      p_input;
};

/*****************************************************************************
 * Prototypes
 *****************************************************************************/
#define playlist_Create(a) __playlist_Create(VLC_OBJECT(a))
playlist_t * __playlist_Create   ( vlc_object_t * );
void           playlist_Destroy  ( playlist_t * );

#define playlist_Play(p) playlist_Command(p,PLAYLIST_PLAY,0)
#define playlist_Pause(p) playlist_Command(p,PLAYLIST_PAUSE,0)
#define playlist_Stop(p) playlist_Command(p,PLAYLIST_STOP,0)
#define playlist_Next(p) playlist_Command(p,PLAYLIST_SKIP,1)
#define playlist_Prev(p) playlist_Command(p,PLAYLIST_SKIP,-1)
#define playlist_Skip(p,i) playlist_Command(p,PLAYLIST_SKIP,i)
#define playlist_Goto(p,i) playlist_Command(p,PLAYLIST_GOTO,i)
VLC_EXPORT( void, playlist_Command, ( playlist_t *, int, int ) );

VLC_EXPORT( int,  playlist_Add,    ( playlist_t *, const char *, int, int ) );
VLC_EXPORT( int,  playlist_AddItem, ( playlist_t *, playlist_item_t *, int, int ) );
VLC_EXPORT( int,  playlist_Delete, ( playlist_t *, int ) );

