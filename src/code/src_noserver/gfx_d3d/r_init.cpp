#include "types.h"
#include "vars.h"
#include <gfx_d3d/gfx_d3d_public.h>
#include <qcommon/qcommon_public.h>
#include <win32/win32_public.h>
#include <database/database_public.h>
#include <physics/phys_colgeom.h>

int g_destroy_window;
bool r_3dmode;
bool g_allocateMinimalResources;

/*
==============
TRACK_r_init
==============
*/
void TRACK_r_init()
{
	UNIMPLEMENTED(__FUNCTION__);
}

// dxerr does not really exist anymore so I'll just import this function
const char* DXGetErrorDescriptionA(HRESULT hr)
{
    const char* result;

    if (hr > 0x8876024B)
    {
        if (hr <= 0x8876026C)
        {
            if (hr == 0x8876026C)
                return "A DC has already been returned for this surface. Only one DC can be retrieved per surface.";
            switch (hr)
            {
            case -2005532084:
                result = "This surface can not be restored because it is an implicitly created surface.";
                break;
            case -2005532083:
                result = "The surface being used is not a palette-based surface";
                break;
            case -2005532082:
                result = "The display is currently in an unsupported mode";
                break;
            case -2005532081:
                result = "Operation could not be carried out because there is no mip-map texture mapping hardware present or available.";
                break;
            case -2005532080:
                result = "The requested action could not be performed because the surface was of the wrong type.";
                break;
            case -2005532072:
                result = "Device does not support optimized surfaces, therefore no video memory optimized surfaces";
                break;
            case -2005532071:
                result = "Surface is an optimized surface, but has not yet been allocated any memory";
                break;
            case -2005532070:
                result = "Attempt was made to create or set a device window without first setting the focus window";
                break;
            case -2005532069:
                result = "Attempt was made to set a palette on a mipmap sublevel";
                break;
            default:
                return "n/a";
            }
            return result;
        }
        if (hr <= -2003238908)
        {
            if (hr == -2003238908)
                return "The geomery scanner failed to process the data.";
            if (hr <= -2005530499)
            {
                if (hr == -2005530499)
                    return "Contect protection not available";
                if (hr > -2005531762)
                {
                    if (hr > -2005530591)
                    {
                        if (hr > -2005530518)
                        {
                            switch (hr)
                            {
                            case -2005530517:
                                return "Invalid device";
                            case -2005530516:
                                return "Invalid call";
                            case -2005530515:
                                return "Driver invalid call";
                            case -2005530512:
                                return "Hardware device was removed";
                            case -2005530508:
                                return "Hardware adapter reset by OS";
                            case -2005530501:
                                return "Overlay is not supported";
                            case -2005530500:
                                return "Overlay format is not supported";
                            }
                        }
                        else
                        {
                            switch (hr)
                            {
                            case -2005530518:
                                return "Not available";
                            case -2005530590:
                                return "Unsupported texture filter";
                            case -2005530586:
                                return "Conflicting texture palette";
                            case -2005530585:
                                return "Driver internal error";
                            case -2005530522:
                                return "Not found";
                            case -2005530521:
                                return "More data";
                            case -2005530520:
                                return "Device lost";
                            case -2005530519:
                                return "Device not reset";
                            }
                        }
                        return "n/a";
                    }
                    if (hr == -2005530591)
                        return "Conflicting render state";
                    if (hr > -2005530600)
                    {
                        switch (hr)
                        {
                        case -2005530599:
                            return "Unsupported color operation";
                        case -2005530598:
                            return "Unsupported color arg";
                        case -2005530597:
                            return "Unsupported alpha operation";
                        case -2005530596:
                            return "Unsupported alpha arg";
                        case -2005530595:
                            return "Too many operations";
                        case -2005530594:
                            return "Conflicting texture filter";
                        case -2005530593:
                            return "Unsupported factor value";
                        }
                        return "n/a";
                    }
                    switch (hr)
                    {
                    case -2005530600:
                        return "Wrong texture format";
                    case -2005531761:
                        return "Bad file";
                    case -2005531760:
                        return "Parse error";
                    case -2005531759:
                        return "Bad array size";
                    case -2005531758:
                        return "Bad data reference";
                    }
                    if (hr != -2005531757)
                    {
                        if (hr == -2005531756)
                            return "No more data";
                        if (hr == -2005531755)
                            return "Bad cache file";
                        return "n/a";
                    }
                }
                else
                {
                    if (hr == -2005531762)
                        return "Bad file float size";
                    if (hr > -2005531801)
                    {
                        switch (hr)
                        {
                        case -2005531800:
                            result = "Bad intrinsics";
                            break;
                        case -2005531799:
                            result = "No more stream handles";
                            break;
                        case -2005531798:
                            return "No more data";
                        case -2005531797:
                            return "Bad cache file";
                        case -2005531796:
                            result = "No internet";
                            break;
                        case -2005531772:
                            result = "Bad object";
                            break;
                        case -2005531771:
                            result = "Bad value";
                            break;
                        case -2005531770:
                            result = "Bad type";
                            break;
                        case -2005531769:
                            return "Not found";
                        case -2005531768:
                            result = "Not done yet";
                            break;
                        case -2005531767:
                            return "File not found";
                        case -2005531766:
                            result = "Resource not found";
                            break;
                        case -2005531765:
                            result = "Bad resource";
                            break;
                        case -2005531764:
                            result = "Bad file type";
                            break;
                        case -2005531763:
                            result = "Bad file version";
                            break;
                        default:
                            return "n/a";
                        }
                        return result;
                    }
                    if (hr != -2005531801)
                    {
                        if (hr <= -2005531978)
                        {
                            if (hr == -2005531978)
                                return "D3D has not yet been initialized.";
                            if (hr <= -2005531982)
                            {
                                switch (hr)
                                {
                                case -2005531982:
                                    return "There is more data available than the specified buffer size could hold";
                                case -2005532042:
                                    return "An attempt was made to allocate non-local video memory from a device that does not support non-local video memory.";
                                case -2005532032:
                                    return "The attempt to page lock a surface failed.";
                                case -2005532012:
                                    return "The attempt to page unlock a surface failed.";
                                case -2005531992:
                                    return "An attempt was made to page unlock a surface with no outstanding page locks.";
                                }
                                return "n/a";
                            }
                            if (hr == -2005531981)
                                return "The data has expired and is therefore no longer valid.";
                            if (hr == -2005531980)
                                return "The mode test has finished executing.";
                            return "The mode test has switched to a new mode.";
                        }
                        switch (hr)
                        {
                        case -2005531977:
                            return "The video port is not active";
                        case -2005531976:
                            return "The monitor does not have EDID data.";
                        case -2005531975:
                            return "The driver does not enumerate display mode refresh rates.";
                        case -2005531973:
                            return "Surfaces created by one direct draw device cannot be used directly by another direct draw device.";
                        }
                        if (hr != -2005531804)
                        {
                            if (hr != -2005531803)
                            {
                                if (hr == -2005531802)
                                    return "Internal error";
                                return "n/a";
                            }
                            return "Bad data reference";
                        }
                        return "Bad array size";
                    }
                }
                return "No more objects";
            }
            if (hr <= -2005270524)
            {
                if (hr == -2005270524)
                    return "Unsupported.";
                if (hr <= -2005401480)
                {
                    if (hr == -2005401480)
                        return "No sound driver is available for use";
                    if (hr > -2005529766)
                    {
                        switch (hr)
                        {
                        case -2005529765:
                            return "Duplicate named fragment";
                        case -2005529764:
                            return "Can Not remove last item";
                        case -2005401590:
                            return "The call failed because resources (such as a priority level) were already being used by another caller";
                        case -2005401570:
                            return "The control (vol, pan, etc.) requested by the caller is not available";
                        case -2005401550:
                            return "This call is not valid for the current state of this object";
                        case -2005401530:
                            return "The caller does not have the priority level required for the function to succeed";
                        case -2005401500:
                            return "The specified WAVE format is not supported";
                        }
                        return "n/a";
                    }
                    if (hr == -2005529766)
                        return "Loaded mesh has no data";
                    if (hr <= -2005529770)
                    {
                        switch (hr)
                        {
                        case -2005529770:
                            return "Cannot attr sort";
                        case -2005530498:
                            return "Unsupported cryptographic system";
                        case -2005530492:
                            return "Presentation statistics are disjoint";
                        case -2005529772:
                            return "Can not modify index buffer";
                        case -2005529771:
                            return "Invalid mesh";
                        }
                        return "n/a";
                    }
                    if (hr == -2005529769)
                        return "Skinning not supported";
                    if (hr == -2005529768)
                        return "Too many influences";
                    return "Invalid data";
                }
                if (hr <= -2005401390)
                {
                    if (hr == -2005401390)
                        return "The GUID specified in an audiopath file does not match a valid MIXIN buffer";
                    if (hr != -2005401470)
                    {
                        if (hr == -2005401450)
                            return "The buffer memory has been lost, and must be restored";
                        if (hr == -2005401440)
                            return "Another app has a higher priority level, preventing this call from succeeding";
                        if (hr != -2005401430)
                        {
                            switch (hr)
                            {
                            case -2005401420:
                                return "Tried to create a DSBCAPS_CTRLFX buffer shorter than DSBSIZE_FX_MIN milliseconds";
                            case -2005401410:
                                return "Attempt to use DirectSound 8 functionality on an older DirectSound object";
                            case -2005401400:
                                return "A circular loop of send effects was detected";
                            }
                            return "n/a";
                        }
                        return "This object has not been initialized";
                    }
                    return "This object is already initialized";
                }
                if (hr == -2005401380)
                    return "Requested effects are not available";
                if (hr == -2005397151)
                    return "The object requested was not found (numerically equal to DMUS_E_NOT_FOUND)";
                if (hr != -2005336063)
                {
                    if (hr != -2005336062)
                    {
                        switch (hr)
                        {
                        case -2005270527:
                            return "The application has made an erroneous API call that it had enough information to avoid. This error is intended to denote that the application should be altered to avoid the error. Use of the debug version of the DXGI.DLL will provide run-time debug output with further information.";
                        case -2005270526:
                            return "The item requested was not found. For GetPrivateData calls, this means that the specified GUID had not been previously associated with the object.";
                        case -2005270525:
                            return "The specified size of the destination buffer is too small to hold the requested data.";
                        }
                        return "n/a";
                    }
                    return "File not found";
                }
                return "There are too many unique state objects.";
            }
            if (hr > -2003435519)
            {
                if (hr > -2003283966)
                {
                    switch (hr)
                    {
                    case -2003283965:
                        return "A font file could not be opened because the file, directory, network location, drive, or other storage location does not exist or is unavailable.";
                    case -2003283964:
                        return "A font file exists but could not be opened due to access denied, sharing violation, or similar error.";
                    case -2003283963:
                        return "A font collection is obsolete due to changes in the system.";
                    case -2003283962:
                        return "The given interface is already registered.";
                    case -2003238911:
                        return "The object was not in the correct state to process the method.";
                    case -2003238910:
                        return "The object has not yet been initialized.";
                    case -2003238909:
                        return "The requested opertion is not supported.";
                    }
                }
                else
                {
                    switch (hr)
                    {
                    case -2003283966:
                        return "Indicates the specified font does not exist.";
                    case -2003435518:
                        return "Hardware XMA decoder error";
                    case -2003435517:
                        return "Failed to create an audio effect";
                    case -2003435516:
                        return "Device invalidated (unplugged, disabled, etc)";
                    case -2003369983:
                        return "Requested audio format unsupported.";
                    case -2003292288:
                        return "The pixel format is not supported.";
                    case -2003283968:
                        return "Indicates an error in an input file such as a font file.";
                    case -2003283967:
                        return "Indicates an error originating in DirectWrite code, which is not expected to occur but is safe to recover from.";
                    }
                }
                return "n/a";
            }
            if (hr == -2003435519)
                return "Invalid XAudio2 API call or arguments";
            if (hr > -2005270495)
            {
                if (hr != -2005270494)
                {
                    if (hr == -2005270493)
                        return "Remote desktop client disconnected.";
                    if (hr == -2005270492)
                        return "Remote desktop client is out of memory.";
                    if (hr != -2005139455)
                    {
                        if (hr != -2005139454)
                        {
                            if (hr == -2005139453)
                                return "Therea are too many unique view objects.";
                            if (hr == -2005139452)
                                return "Deferred context requires Map-Discard usage pattern";
                            return "n/a";
                        }
                        return "File not found";
                    }
                    return "There are too many unique state objects.";
                }
            }
            else
            {
                switch (hr)
                {
                case -2005270495:
                    return "The application attempted to perform an operation on an DXGI output that is only legal after the output has been claimed for exclusive owenership.";
                case -2005270523:
                    return "Hardware device removed.";
                case -2005270522:
                    return "Device hung due to badly formed commands.";
                case -2005270521:
                    return "Device reset due to a badly formed commant.";
                case -2005270518:
                    return "Was still drawing.";
                }
                if (hr != -2005270517 && hr != -2005270516)
                {
                    if (hr == -2005270496)
                        return "An internal driver error occurred.";
                    return "n/a";
                }
            }
            return "The requested functionality is not supported by the device or the driver.";
        }
        if (hr <= -1966669823)
        {
            if (hr == -1966669823)
                return "The engine is already initialized.";
            switch (hr)
            {
            case -2003238907:
                result = "D2D could not access the screen.";
                break;
            case -2003238906:
                result = "A valid display state could not be determined.";
                break;
            case -2003238905:
                result = "The supplied vector is zero.";
                break;
            case -2003238904:
                result = "An internal error (D2D bug) occurred. On checked builds, we would assert.";
                break;
            case -2003238903:
                result = "The display format we need to render is not supported by the hardware device.";
                break;
            case -2003238902:
                result = "A call to this method is invalid.";
                break;
            case -2003238901:
                result = "No HW rendering device is available for this operation.";
                break;
            case -2003238900:
                result = "here has been a presentation error that may be recoverable. The caller needs to recreate, rerender the entire frame, and reattempt present.";
                break;
            case -2003238899:
                result = "Shader construction failed because it was too complex.";
                break;
            case -2003238898:
                result = "Shader compilation failed.";
                break;
            case -2003238897:
                result = "Requested DX surface size exceeded maximum texture size.";
                break;
            case -2003238896:
                result = "The requested D2D version is not supported.";
                break;
            case -2003238895:
                result = "Invalid number.";
                break;
            case -2003238894:
                result = "Objects used together must be created from the same factory instance.";
                break;
            case -2003238893:
                result = "A layer resource can only be in use once at any point in time.";
                break;
            case -2003238892:
                result = "The pop call did not match the corresponding push call";
                break;
            case -2003238890:
                result = "The push and pop calls were unbalanced";
                break;
            case -2003238889:
                result = "Attempt to copy from a render target while a layer or clip rect is applied";
                break;
            case -2003238888:
                result = "The brush types are incompatible for the call.";
                break;
            case -2003238887:
                result = "An unknown win32 failure occurred.";
                break;
            case -2003238886:
                result = "The render target is not compatible with GDI";
                break;
            case -2003238885:
                result = "A text client drawing effect object is of the wrong type";
                break;
            case -2003238884:
                result = "The application is holding a reference to the IDWriteTextRenderer interface after the corresponding DrawText or DrawTextLayout call has returned. The IDWriteTextRenderer instance will be zombied.";
                break;
            default:
                return "n/a";
            }
            return result;
        }
        if (hr <= -1966669567)
        {
            if (hr == -1966669567)
                return "Error writing a file during auditioning.";
            switch (hr)
            {
            case -1966669822:
                result = "The engine has not been initialized.";
                break;
            case -1966669821:
                result = "The engine has expired (demo or pre-release version).";
                break;
            case -1966669820:
                result = "No notification callback.";
                break;
            case -1966669819:
                result = "Notification already registered.";
                break;
            case -1966669818:
                result = "Invalid usage.";
                break;
            case -1966669817:
                result = "Invalid data.";
                break;
            case -1966669816:
                result = "Fail to play due to instance limit.";
                break;
            case -1966669815:
                result = "Global Settings not loaded.";
                break;
            case -1966669814:
                result = "Invalid variable index.";
                break;
            case -1966669813:
                result = "Invalid category.";
                break;
            case -1966669812:
                result = "Invalid cue index.";
                break;
            case -1966669811:
                result = "Invalid wave index.";
                break;
            case -1966669810:
                result = "Invalid track index.";
                break;
            case -1966669809:
                result = "Invalid sound offset or index.";
                break;
            case -1966669808:
                result = "Error reading a file.";
                break;
            case -1966669807:
                result = "Unknown event type.";
                break;
            case -1966669806:
                result = "Invalid call of method of function from callback.";
                break;
            case -1966669805:
                result = "No wavebank exists for desired operation.";
                break;
            case -1966669804:
                result = "Unable to select a variation.";
                break;
            case -1966669803:
                result = "There can be only one audition engine.";
                break;
            case -1966669802:
                result = "The wavebank is not prepared.";
                break;
            case -1966669801:
                result = "No audio device found.";
                break;
            case -1966669800:
                result = "Invalid entry count for channel maps.";
                break;
            case -1966669799:
                result = "Time offset for seeking is beyond the cue end.";
                break;
            case -1966669798:
                result = "Time offset for seeking is beyond the wave end.";
                break;
            case -1966669797:
                result = "Friendly names are not included in the bank.";
                break;
            default:
                return "n/a";
            }
            return result;
        }
        if (hr <= 8)
        {
            if (hr == 8)
                return "Not enough storage is available to process this command.";
            if (hr <= -1072898028)
            {
                if (hr == -1072898028)
                    return "Element content is invalid according to the DTD or schema.";
                if (hr > -1072898045)
                {
                    switch (hr)
                    {
                    case -1072898044:
                        result = "Cannot use the NDATA keyword in a parameter entity declaration.";
                        break;
                    case -1072898043:
                        result = "Cannot use a general parsed entity '%1' as the value for attribute '%2'.";
                        break;
                    case -1072898042:
                        result = "Cannot use unparsed entity '%1' in an entity reference.";
                        break;
                    case -1072898041:
                        result = "Cannot reference an external general parsed entity '%1' in an attribute value.";
                        break;
                    case -1072898035:
                        result = "The element '%1' is used but not declared in the DTD or schema.";
                        break;
                    case -1072898034:
                        result = "The attribute '%1' references the ID '%2', which is not defined in the document.";
                        break;
                    case -1072898031:
                        result = "Element cannot be empty according to the DTD or schema.";
                        break;
                    case -1072898030:
                        result = "Element content is incomplete according to the DTD or schema.";
                        break;
                    case -1072898029:
                        result = "The name of the top-most element must match the name of the DOCTYPE declaration.";
                        break;
                    default:
                        return "n/a";
                    }
                }
                else
                {
                    if (hr == -1072898045)
                        return "Entity '%1' contains an infinite entity reference loop.";
                    if (hr > -1966669562)
                    {
                        switch (hr)
                        {
                        case -1966669561:
                            return "Wave does not exist in auditioned wavebank.";
                        case -1966669560:
                            return "Failed to create a directory for streaming wavebank data.";
                        case -1966669559:
                            return "Invalid audition session.";
                        case -1072898046:
                            return "Reference to undefined entity '%1'.";
                        }
                        return "n/a";
                    }
                    switch (hr)
                    {
                    case -1966669562:
                        return "Missing a DSP parameter.";
                    case -1966669566:
                        return "Missing a soundbank.";
                    case -1966669565:
                        return "Missing an RPC curve.";
                    case -1966669564:
                        return "Missing data for an audition command.";
                    default:
                        return "Unknown command.";
                    }
                }
                return result;
            }
            if (hr <= -1072897501)
            {
                if (hr == -1072897501)
                    return "The validate method failed because the document does not contain exactly one root node.";
                switch (hr)
                {
                case -1072898027:
                    result = "The attribute '%1' on this element is not defined in the DTD or schema.";
                    break;
                case -1072898026:
                    result = "Attribute '%1' has a value that does not match the fixed value defined in the DTD or schema.";
                    break;
                case -1072898025:
                    result = "Attribute '%1' has an invalid value according to the DTD or schema.";
                    break;
                case -1072898024:
                    result = "Text is not allowed in this element according to the DTD or schema.";
                    break;
                case -1072898023:
                    result = "An attribute declaration cannot contain multiple fixed values: '%1'.";
                    break;
                case -1072898020:
                    result = "Reference to undeclared element: '%1'.";
                    break;
                case -1072898018:
                    result = "Attribute '%1' must be a #FIXED attribute.";
                    break;
                case -1072898016:
                    result = "Required attribute '%1' is missing.";
                    break;
                case -1072898010:
                    result = "Expecting: %1.";
                    break;
                default:
                    return "n/a";
                }
                return result;
            }
            if (hr > 3)
            {
                switch (hr)
                {
                case 4:
                    return "The system cannot open the file.";
                case 5:
                    return "Access is denied.";
                case 6:
                    return "The handle is invalid.";
                }
                return "n/a";
            }
            switch (hr)
            {
            case 3:
                return "The system cannot find the path specified.";
            case -1072897500:
                return "The validate method failed because a DTD or schema was not specified in the document.";
            case 0:
                return "The function completed successfully";
            case 1:
                return "Call successful, but returned FALSE";
            case 2:
                return "The system cannot find the file specified.";
            }
            return "n/a";
        }
        if (hr <= 262760)
        {
            if (hr == 262760)
                return "The graph can't be cued because of lack of or corrupt data.";
            if (hr > 262725)
            {
                if (hr > 262744)
                {
                    switch (hr)
                    {
                    case 262746:
                        return "Cannot play back the video stream: format 'RPZA' is not supported.";
                    case 262752:
                        return "The value returned had to be estimated.  It's accuracy can not be guaranteed.";
                    case 262755:
                        return "This success code is reserved for internal purposes within ActiveMovie.";
                    case 262759:
                        return "The stream has been turned off.";
                    }
                }
                else
                {
                    switch (hr)
                    {
                    case 262744:
                        return "Cannot play back the audio stream: no audio hardware is available.";
                    case 262726:
                        return "Some connections have failed and have been deferred.";
                    case 262736:
                        return "The resource specified is no longer needed.";
                    case 262740:
                        return "A connection could not be made with the media type in the persistent graph, but has been made with a negotiated media type.";
                    case 262743:
                        return "Cannot play back the video stream: no suitable decompressor could be found.";
                    }
                }
            }
            else
            {
                if (hr == 262725)
                    return "The file contained some property settings that were not used.";
                if (hr > 262147)
                {
                    switch (hr)
                    {
                    case 262403:
                        return "The end of the list has been reached.";
                    case 262701:
                        return "An attempt to add a filter with a duplicate name succeeded with a modified name.";
                    case 262711:
                        return "The state transition has not completed.";
                    case 262722:
                        return "Some of the streams in this movie are in an unsupported format.";
                    }
                }
                else
                {
                    switch (hr)
                    {
                    case 262147:
                        return "End of stream. Sample not updated.";
                    case 9:
                        return "The storage control block address is invalid.";
                    case 10:
                        return "The environment is incorrect.";
                    case 11:
                        return "An attempt was made to load a program with an incorrect format.";
                    case 14:
                        return "The system cannot find the drive specified.";
                    }
                }
            }
            return "n/a";
        }
        if (hr <= 141953144)
        {
            if (hr == 141953144)
                return "Client window is occluded (minimized or other fullscreen)";
            if (hr > 262797)
            {
                switch (hr)
                {
                case 141953135:
                    return "The call succeeded but there won't be any mipmaps generated";
                case 141953141:
                    return "Resource not resident in memory";
                case 141953142:
                    return "Resource resident in shared memory";
                case 141953143:
                    return "Desktop display mode has changed";
                }
            }
            else
            {
                switch (hr)
                {
                case 262797:
                    return "The seek into the movie was not frame accurate.";
                case 262768:
                    return "The stop time for the sample was not set.";
                case 262782:
                    return "There was no preview pin available, so the capture pin output is being split to provide both capture and preview.";
                case 262784:
                    return "The current title was not a sequential set of chapters (PGC), and the returned timing information might not be continuous.";
                case 262796:
                    return "The audio stream did not contain sufficient information to determine the contents of each channel.";
                }
            }
            return "n/a";
        }
        if (hr > 142213125)
        {
            if (hr != 142213126)
            {
                if (hr == 142213127)
                    return "Display mode has changed";
                if (hr == 142213128)
                    return "Display mode is changing";
                return "n/a";
            }
        }
        else
        {
            switch (hr)
            {
            case 142213125:
                return "No access to desktop.";
            case 142082058:
                return "The call succeeded, but we had to substitute the 3D algorithm";
            case 142213121:
                return "The target window or output has been occluded. The application should suspend rendering operations if possible.";
            case 142213122:
                return "Target window is clipped.";
            }
            if (hr != 142213124)
                return "n/a";
        }
        return "";
    }
    if (hr == 0x8876024B)
        return "This surface can not be restored because it was created in a different mode.";
    if (hr > -2147220494)
    {
        if (hr <= -2147219199)
        {
            if (hr == -2147219199)
                return "Could not initialize Direct3D.";
            switch (hr)
            {
            case -2147220481:
                result = "Device installer errors.";
                break;
            case -2147220480:
                result = "Registry entry or DLL for class installer invalid or class installer not found.";
                break;
            case -2147220479:
                result = "The user cancelled the install operation. & The stream already has allocated samples and the surface doesn't match the sample format.";
                break;
            case -2147220478:
                result = "The INF file for the selected device could not be found or is invalid or is damaged. & The specified purpose ID can't be used for the call.";
                break;
            case -2147220477:
                result = "No stream can be found with the specified attributes.";
                break;
            case -2147220476:
                result = "Seeking not supported for this object.";
                break;
            case -2147220475:
                result = "The stream formats are not compatible.";
                break;
            case -2147220474:
                result = "The sample is busy.";
                break;
            case -2147220473:
                result = "The object can't accept the call because its initialize function or equivalent has not been called.";
                break;
            case -2147220472:
                result = "MS_E_SOURCEALREADYDEFINED";
                break;
            case -2147220471:
                result = "The stream type is not valid for this operation.";
                break;
            case -2147220470:
                result = "The object is not in running state.";
                break;
            default:
                return "n/a";
            }
            return result;
        }
        if (hr <= -2147024894)
        {
            if (hr != -2147024894)
            {
                switch (hr)
                {
                case -2147219198:
                    result = "No device could be found with the specified device settings.";
                    break;
                case -2147219197:
                    result = "A media file could not be found.";
                    break;
                case -2147219196:
                    result = "The device interface has a non-zero reference count, meaning that some objects were not released.";
                    break;
                case -2147219195:
                    result = "An error occurred when attempting to create a device.";
                    break;
                case -2147219194:
                    result = "An error occurred when attempting to reset a device.";
                    break;
                case -2147219193:
                    result = "An error occurred in the device create callback function.";
                    break;
                case -2147219192:
                    result = "An error occurred in the device reset callback function.";
                    break;
                case -2147219191:
                    result = "Incorrect version of Direct3D or D3DX.";
                    break;
                case -2147219190:
                    result = "The device was removed.";
                    break;
                default:
                    return "n/a";
                }
                return result;
            }
            return "The system cannot find the file specified.";
        }
        if (hr <= -2147024875)
        {
            if (hr != -2147024875)
            {
                switch (hr)
                {
                case -2147024893:
                    return "The system cannot find the path specified.";
                case -2147024892:
                    return "The system cannot open the file.";
                case -2147024891:
                    result = "Access is denied";
                    break;
                case -2147024890:
                    result = "Invalid handle";
                    break;
                case -2147024888:
                    return "Not enough storage is available to process this command.";
                case -2147024887:
                    return "The storage control block address is invalid.";
                case -2147024886:
                    return "The environment is incorrect.";
                case -2147024885:
                    return "An attempt was made to load a program with an incorrect format.";
                case -2147024884:
                    result = "The operation cannot be performed unless the device is acquired.";
                    break;
                case -2147024882:
                    result = "Ran out of memory";
                    break;
                default:
                    return "n/a";
                }
                return result;
            }
            return "This object has not been initialized";
        }
        if (hr > -2005532322)
        {
            if (hr <= -2005532110)
            {
                if (hr == -2005532110)
                    return "A DirectDraw object representing this driver has already been created for this process.";
                if (hr > -2005532212)
                {
                    if (hr > -2005532151)
                    {
                        switch (hr)
                        {
                        case -2005532135:
                            return "vertical blank is in progress";
                        case -2005532132:
                            return "Was still drawing";
                        case -2005532130:
                            return "The specified surface type requires specification of the COMPLEX flag";
                        case -2005532112:
                            return "Rectangle provided was not horizontally aligned on reqd. boundary";
                        case -2005532111:
                            return "The GUID passed to DirectDrawCreate is not a valid DirectDraw driver identifier.";
                        }
                    }
                    else
                    {
                        switch (hr)
                        {
                        case -2005532151:
                            return "The specified stream contains invalid data";
                        case -2005532202:
                            return "Height requested by DirectDraw is too large.";
                        case -2005532192:
                            return "Size requested by DirectDraw is too large --  The individual height and width are OK.";
                        case -2005532182:
                            return "Width requested by DirectDraw is too large.";
                        case -2005532162:
                            return "Pixel format requested is unsupported by DirectDraw";
                        case -2005532152:
                            return "Bitmask in the pixel format requested is unsupported by DirectDraw";
                        }
                    }
                }
                else
                {
                    if (hr == -2005532212)
                        return "The requested surface is not attached.";
                    if (hr > -2005532262)
                    {
                        switch (hr)
                        {
                        case -2005532252:
                            return "This surface is already a dependency of the surface it is being made a dependency of.";
                        case -2005532242:
                            return "Access to this surface is being refused because the surface is already locked by another thread.";
                        case -2005532237:
                            return "Access to this surface is being refused because no driver exists which can supply a pointer to the surface. This is most likely to happen when attempting to lock the primary surface when no DCI provider is present. Will also happen on attempts to lock an optimized surface.";
                        case -2005532232:
                            return "Access to Surface refused because Surface is obscured.";
                        case -2005532222:
                            return "Access to this surface is being refused because the surface is gone. The DIRECTDRAWSURFACE object representing this surface should have Restore called on it.";
                        }
                    }
                    else
                    {
                        switch (hr)
                        {
                        case -2005532262:
                            return "This surface is already attached to the surface it is being attached to.";
                        case -2005532312:
                            return "The hardware needed for the requested operation has already been allocated.";
                        case -2005532292:
                            return "Out of video memory";
                        case -2005532290:
                            return "hardware does not support clipped overlays";
                        case -2005532288:
                            return "Can only have ony color key active at one time for overlays";
                        case -2005532285:
                            return "Access to this palette is being refused because the palette is already locked by another thread.";
                        case -2005532272:
                            return "No src color key specified for this operation.";
                        }
                    }
                }
                return "n/a";
            }
            switch (hr)
            {
            case -2005532109:
                result = "A hardware only DirectDraw object creation was attempted but the driver did not support any hardware.";
                break;
            case -2005532108:
                result = "this process already has created a primary surface";
                break;
            case -2005532107:
                result = "software emulation not available.";
                break;
            case -2005532106:
                result = "region passed to Clipper::GetClipList is too small.";
                break;
            case -2005532105:
                result = "an attempt was made to set a clip list for a clipper objec that is already monitoring an hwnd.";
                break;
            case -2005532104:
                result = "No clipper object attached to surface object";
                break;
            case -2005532103:
                result = "Clipper notification requires an HWND or no HWND has previously been set as the CooperativeLevel HWND.";
                break;
            case -2005532102:
                result = "HWND used by DirectDraw CooperativeLevel has been subclassed, this prevents DirectDraw from restoring state.";
                break;
            case -2005532101:
                result = "The CooperativeLevel HWND has already been set. It can not be reset while the process has surfaces or palettes created.";
                break;
            case -2005532100:
                result = "No palette object attached to this surface.";
                break;
            case -2005532099:
                result = "No hardware support for 16 or 256 color palettes.";
                break;
            case -2005532098:
                result = "If a clipper object is attached to the source surface passed into a BltFast call.";
                break;
            case -2005532097:
                result = "No blter.";
                break;
            case -2005532096:
                result = "No DirectDraw ROP hardware.";
                break;
            case -2005532095:
                result = "returned when GetOverlayPosition is called on a hidden overlay";
                break;
            case -2005532094:
                result = "returned when GetOverlayPosition is called on a overlay that UpdateOverlay has never been called on to establish a destionation.";
                break;
            case -2005532093:
                result = "returned when the position of the overlay on the destionation is no longer legal for that destionation.";
                break;
            case -2005532092:
                result = "returned when an overlay member is called for a non-overlay surface";
                break;
            case -2005532091:
                result = "An attempt was made to set the cooperative level when it was already set to exclusive.";
                break;
            case -2005532090:
                result = "An attempt has been made to flip a surface that is not flippable.";
                break;
            case -2005532089:
                result = "Can't duplicate primary & 3D surfaces, or surfaces that are implicitly created.";
                break;
            case -2005532088:
                result = "Surface was not locked.  An attempt to unlock a surface that was not locked at all, or by this process, has been attempted.";
                break;
            case -2005532087:
                result = "Windows can not create any more DCs, or a DC was requested for a paltte-indexed surface when the surface had no palette AND the display mode was not palette-indexed (in this case DirectDraw cannot select a proper palette into the DC)";
                break;
            case -2005532086:
                result = "No DC was ever created for this surface.";
                break;
            default:
                return "n/a";
            }
            return result;
        }
        if (hr == -2005532322)
            return "Overlay surfaces could not be z layered based on their BltOrder because the hardware does not support z layering of overlays.";
        if (hr > -2005532492)
        {
            if (hr > -2005532417)
            {
                if (hr > -2005532356)
                {
                    switch (hr)
                    {
                    case -2005532355:
                        return "DirectDrawSurface is not in 4 bit color index palette and the requested operation requires 4 bit color index palette.";
                    case -2005532352:
                        return "DirectDraw Surface is not in 8 bit color mode and the requested operation requires 8 bit color.";
                    case -2005532342:
                        return "Operation could not be carried out because there is no texture mapping hardware present or available.";
                    case -2005532337:
                        return "Operation could not be carried out because there is no hardware support for vertical blank synchronized operations.";
                    case -2005532332:
                        return "Operation could not be carried out because there is no hardware support for zbuffer blting.";
                    }
                }
                else
                {
                    switch (hr)
                    {
                    case -2005532356:
                        return "DirectDrawSurface is not in 4 bit color palette and the requested operation requires 4 bit color palette.";
                    case -2005532412:
                        return "Operation could not be carried out because there is no overlay hardware present or available.";
                    case -2005532402:
                        return "Operation could not be carried out because the source and destination rectangles are on the same surface and overlap each other.";
                    case -2005532392:
                        return "Operation could not be carried out because there is no appropriate raster op hardware present or available.";
                    case -2005532382:
                        return "Operation could not be carried out because there is no rotation hardware present or available.";
                    case -2005532362:
                        return "Operation could not be carried out because there is no hardware support for stretching";
                    }
                }
            }
            else
            {
                if (hr == -2005532417)
                    return "Requested item was not found";
                if (hr > -2005532452)
                {
                    switch (hr)
                    {
                    case -2005532450:
                        return "No DirectDraw support possible with current display driver";
                    case -2005532447:
                        return "Operation requires the application to have exclusive mode but the application does not have exclusive mode.";
                    case -2005532442:
                        return "Flipping visible surfaces is not supported.";
                    case -2005532432:
                        return "There is no GDI present.";
                    case -2005532422:
                        return "Operation could not be carried out because there is no hardware present or available.";
                    }
                }
                else
                {
                    switch (hr)
                    {
                    case -2005532452:
                        return "Operation could not be carried out because there is no hardware support of the dest color key.";
                    case -2005532491:
                        return "Operation could not be carried out because there is no stereo hardware present or available.";
                    case -2005532490:
                        return "Operation could not be carried out because there is no hardware present which supports stereo surfaces";
                    case -2005532467:
                        return "no clip list available";
                    case -2005532462:
                        return "Operation could not be carried out because there is no color conversion hardware present or available.";
                    case -2005532460:
                        return "Create function called without DirectDraw object method SetCooperativeLevel being called.";
                    case -2005532457:
                        return "Surface doesn't currently have a color key";
                    }
                }
            }
            return "n/a";
        }
        if (hr == -2005532492)
            return "Operation could not be carried out because there is no alpha accleration hardware present or available.";
        if (hr > -2005532652)
        {
            if (hr > -2005532552)
            {
                switch (hr)
                {
                case -2005532542:
                    return "DirectDraw received a pointer that was an invalid DIRECTDRAW object.";
                case -2005532527:
                    return "pixel format was invalid as specified";
                case -2005532522:
                    return "Rectangle provided was invalid.";
                case -2005532512:
                    return "Operation could not be carried out because one or more surfaces are locked";
                case -2005532502:
                    return "There is no 3D present.";
                }
            }
            else
            {
                switch (hr)
                {
                case -2005532552:
                    return "DirectDraw does not support the requested mode";
                case -2005532632:
                    return "Support is currently not available.";
                case -2005532617:
                    return "An exception was encountered while performing the requested operation";
                case -2005532582:
                    return "Height of rectangle provided is not a multiple of reqd alignment";
                case -2005532577:
                    return "Unable to match primary surface creation request with existing primary surface.";
                case -2005532572:
                    return "One or more of the caps bits passed to the callback are incorrect.";
                case -2005532562:
                    return "DirectDraw does not support provided Cliplist.";
                }
            }
            return "n/a";
        }
        if (hr == -2005532652)
            return "This surface can not be detached from the requested surface.";
        if (hr <= -2147023743)
        {
            switch (hr)
            {
            case -2147023743:
                return "The application was written for an unsupported prerelease version of DirectInput.";
            case -2147024866:
                return "Access to the device has been lost.  It must be re-acquired.";
            case -2147024809:
                return "An invalid parameter was passed to the returning function";
            case -2147024777:
                return "The object could not be created due to an incompatible driver version or mismatched or incomplete driver components.";
            case -2147024726:
                return "The operation cannot be performed while the device is acquired.";
            case -2147024637:
                return "No more items.";
            case -2147023746:
                return "The application requires a newer version of DirectInput.";
            }
            return "n/a";
        }
        if (hr == -2147023728)
            return "The specified property ID is not supported for the specified property set.";
        if (hr == -2147023726)
            return "The specified property set is not supported.";
        if (hr != -2147023649 && hr != -2005532667)
        {
            if (hr == -2005532662)
                return "This surface can not be attached to the requested surface.";
            return "n/a";
        }
        return "This object is already initialized";
    }
    if (hr == -2147220494)
        return "A registry entry is corrupt.";
    if (hr > -2147220935)
    {
        switch (hr)
        {
        case -2147220934:
            result = "A full-screen mode is not available.";
            break;
        case -2147220933:
            result = "Cannot call IVideoWindow methods while in full-screen mode.";
            break;
        case -2147220928:
            result = "The media type of this file is not recognized.";
            break;
        case -2147220927:
            result = "The source filter for this file could not be loaded.";
            break;
        case -2147220925:
            result = "A file appeared to be incomplete.";
            break;
        case -2147220924:
            result = "The version number of the file is invalid.";
            break;
        case -2147220921:
            result = "This file is corrupt: it contains an invalid class identifier.";
            break;
        case -2147220920:
            result = "This file is corrupt: it contains an invalid media type.";
            break;
        case -2147220919:
            result = "No time stamp has been set for this sample.";
            break;
        case -2147220911:
            result = "No media time stamp has been set for this sample.";
            break;
        case -2147220910:
            result = "No media time format has been selected.";
            break;
        case -2147220909:
            result = "Cannot change balance because audio device is mono only.";
            break;
        case -2147220907:
            return "Cannot play back the video stream: no suitable decompressor could be found.";
        case -2147220906:
            result = "Cannot play back the audio stream: no audio hardware is available, or the hardware is not responding.";
            break;
        case -2147220903:
            return "Cannot play back the video stream: format 'RPZA' is not supported.";
        case -2147220901:
            result = "ActiveMovie cannot play MPEG movies on this processor.";
            break;
        case -2147220900:
            result = "Cannot play back the audio stream: the audio format is not supported.";
            break;
        case -2147220899:
            result = "Cannot play back the video stream: the video format is not supported.";
            break;
        case -2147220898:
            result = "ActiveMovie cannot play this video stream because it falls outside the constrained standard.";
            break;
        case -2147220897:
            result = "Cannot perform the requested function on an object that is not in the filter graph.";
            break;
        case -2147220895:
            result = "Cannot get or set time related information on an object that is using a time format of TIME_FORMAT_NONE.";
            break;
        case -2147220894:
            result = "The connection cannot be made because the stream is read only and the filter alters the data.";
            break;
        case -2147220892:
            result = "The buffer is not full enough.";
            break;
        case -2147220891:
            result = "Cannot play back the file.  The format is not supported.";
            break;
        case -2147220890:
            result = "Pins cannot connect due to not supporting the same transport.";
            break;
        case -2147220887:
            result = "The Video CD can't be read correctly by the device or is the data is corrupt.";
            break;
        case -2147220879:
            result = "There is not enough Video Memory at this display resolution and number of colors. Reducing resolution might help.";
            break;
        case -2147220878:
            result = "The VideoPort connection negotiation process has failed.";
            break;
        case -2147220877:
            result = "Either DirectDraw has not been installed or the Video Card capabilities are not suitable. Make sure the display is not in 16 color mode.";
            break;
        case -2147220876:
            result = "No VideoPort hardware is available, or the hardware is not responding.";
            break;
        case -2147220875:
            result = "No Capture hardware is available, or the hardware is not responding.";
            break;
        case -2147220874:
            result = "This User Operation is inhibited by DVD Content at this time.";
            break;
        case -2147220873:
            result = "This Operation is not permitted in the current domain.";
            break;
        case -2147220872:
            result = "The specified button is invalid or is not present at the current time, or there is no button present at the specified location.";
            break;
        case -2147220871:
            result = "DVD-Video playback graph has not been built yet.";
            break;
        case -2147220870:
            result = "DVD-Video playback graph building failed.";
            break;
        case -2147220869:
            result = "DVD-Video playback graph could not be built due to insufficient decoders.";
            break;
        case -2147220868:
            result = "Version number of DirectDraw not suitable. Make sure to install dx5 or higher version.";
            break;
        case -2147220867:
            result = "Copy protection cannot be enabled. Please make sure any other copy protected content is not being shown now.";
            break;
        case -2147220865:
            result = "This object cannot be used anymore as its time has expired.";
            break;
        case -2147220863:
            result = "The operation cannot be performed at the current playback speed.";
            break;
        case -2147220862:
            result = "The specified menu doesn't exist.";
            break;
        case -2147220861:
            result = "The specified command was either cancelled or no longer exists.";
            break;
        case -2147220860:
            result = "The data did not contain a recognized version.";
            break;
        case -2147220859:
            result = "The state data was corrupt.";
            break;
        case -2147220858:
            result = "The state data is from a different disc.";
            break;
        case -2147220857:
            result = "The region was not compatible with the current drive.";
            break;
        case -2147220856:
            result = "The requested DVD stream attribute does not exist.";
            break;
        case -2147220855:
            result = "Currently there is no GoUp (Annex J user function) program chain (PGC).";
            break;
        case -2147220854:
            result = "The current parental level was too low.";
            break;
        case -2147220853:
            result = "The current audio is not karaoke content.";
            break;
        case -2147220850:
            result = "Frame step is not supported on this configuration.";
            break;
        case -2147220849:
            result = "The specified stream is disabled and cannot be selected.";
            break;
        case -2147220848:
            result = "The operation depends on the current title number, however the navigator has not yet entered the VTSM or the title domains, so the 'current' title index is unknown.";
            break;
        case -2147220847:
            result = "The specified path does not point to a valid DVD disc.";
            break;
        case -2147220846:
            result = "There is currently no resume information.";
            break;
        case -2147220845:
            result = "This thread has already blocked this output pin.  There is no need to call IPinFlowControl::Block() again.";
            break;
        case -2147220844:
            result = "IPinFlowControl::Block() has been called on another thread.  The current thread cannot make any assumptions about this pin's block state.";
            break;
        case -2147220843:
            result = "An operation failed due to a certification failure.";
            break;
        case -2147220736:
            result = "Device driver-specific codes. Unless the specific driver has been precisely identified, no meaning should be attributed to these values other than that the driver originated the error.";
            break;
        case -2147220735:
            result = "DIERR_DRIVERFIRST+1";
            break;
        case -2147220734:
            result = "DIERR_DRIVERFIRST+2";
            break;
        case -2147220733:
            result = "DIERR_DRIVERFIRST+3";
            break;
        case -2147220732:
            result = "DIERR_DRIVERFIRST+4";
            break;
        case -2147220731:
            result = "DIERR_DRIVERFIRST+5";
            break;
        case -2147220713:
            result = "Debugger is present.";
            break;
        default:
            return "n/a";
        }
    }
    else
    {
        if (hr == -2147220935)
            return "This Advise cannot be canceled because it was not successfully set.";
        if (hr > -2147220970)
        {
            switch (hr)
            {
            case -2147220969:
                result = "No combination of intermediate filters could be found to make the connection.";
                break;
            case -2147220968:
                result = "No combination of filters could be found to render the stream.";
                break;
            case -2147220967:
                result = "Could not change formats dynamically.";
                break;
            case -2147220966:
                result = "No color key has been set.";
                break;
            case -2147220965:
                result = "Current pin connection is not using the IOverlay transport.";
                break;
            case -2147220964:
                result = "Current pin connection is not using the IMemInputPin transport.";
                break;
            case -2147220963:
                result = "Setting a color key would conflict with the palette already set.";
                break;
            case -2147220962:
                result = "Setting a palette would conflict with the color key already set.";
                break;
            case -2147220961:
                result = "No matching color key is available.";
                break;
            case -2147220960:
                result = "No palette is available.";
                break;
            case -2147220959:
                result = "Display does not use a palette.";
                break;
            case -2147220958:
                result = "Too many colors for the current display settings.";
                break;
            case -2147220957:
                result = "The state changed while waiting to process the sample.";
                break;
            case -2147220956:
                result = "The operation could not be performed because the filter is not stopped.";
                break;
            case -2147220955:
                result = "The operation could not be performed because the filter is not paused.";
                break;
            case -2147220954:
                result = "The operation could not be performed because the filter is not running.";
                break;
            case -2147220953:
                result = "The operation could not be performed because the filter is in the wrong state.";
                break;
            case -2147220952:
                result = "The sample start time is after the sample end time.";
                break;
            case -2147220951:
                result = "The supplied rectangle is invalid.";
                break;
            case -2147220950:
                result = "This pin cannot use the supplied media type.";
                break;
            case -2147220949:
                result = "This sample cannot be rendered.";
                break;
            case -2147220948:
                result = "This sample cannot be rendered because the end of the stream has been reached.";
                break;
            case -2147220947:
                result = "An attempt to add a filter with a duplicate name failed.";
                break;
            case -2147220946:
                result = "A time-out has expired.";
                break;
            case -2147220945:
                result = "The file format is invalid.";
                break;
            case -2147220944:
                result = "The list has already been exhausted.";
                break;
            case -2147220943:
                result = "The filter graph is circular.";
                break;
            case -2147220942:
                result = "Updates are not allowed in this state.";
                break;
            case -2147220941:
                result = "An attempt was made to queue a command for a time in the past.";
                break;
            case -2147220940:
                result = "The queued command has already been canceled.";
                break;
            case -2147220939:
                result = "Cannot render the file because it is corrupt.";
                break;
            case -2147220938:
                result = "An overlay advise link already exists.";
                break;
            case -2147220936:
                result = "No full-screen modes are available.";
                break;
            default:
                return "n/a";
            }
        }
        else
        {
            if (hr == -2147220970)
                return "An object or name was not found.";
            if (hr <= -2147220987)
            {
                if (hr == -2147220987)
                    return "The operation cannot be performed unless the device is acquired in DISCL_EXCLUSIVE mode. & This operation cannot be performed because the filter is active.";
                if (hr > -2147221164)
                {
                    switch (hr)
                    {
                    case -2147221008:
                        return "CoInitialize has not been called.";
                    case -2147221007:
                        return "CoInitialize has already been called.";
                    case -2147220992:
                        return "Unable to IDirectInputJoyConfig_Acquire because the user does not have sufficient privileges to change the joystick configuration. & An invalid media type was specified";
                    case -2147220991:
                        return "The device is full. & An invalid media subtype was specified.";
                    case -2147220990:
                        return "Not all the requested information fit into the buffer. & This object can only be created as an aggregated object.";
                    case -2147220989:
                        return "The effect is not downloaded. & The enumerator has become invalid.";
                    case -2147220988:
                        return "The device cannot be reinitialized because there are still effects attached to it. & At least one of the pins involved in the operation is already connected.";
                    }
                }
                else
                {
                    if (hr == -2147221164)
                        return "Class not registered";
                    if (hr > -2147467260)
                    {
                        switch (hr)
                        {
                        case -2147467259:
                            return "An undetermined error occurred";
                        case -2147418113:
                            return "Catastrophic failure";
                        case -2147221232:
                            return "This object does not support aggregation";
                        }
                    }
                    else
                    {
                        switch (hr)
                        {
                        case -2147467260:
                            return "Operation aborted";
                        case -2147483638:
                            return "The data necessary to complete this operation is not yet available.";
                        case -2147467263:
                            return "The function called is not supported at this time";
                        case -2147467262:
                            return "The requested COM interface is not available";
                        case -2147467261:
                            return "Invalid pointer";
                        }
                    }
                }
                return "n/a";
            }
            switch (hr)
            {
            case -2147220986:
                result = "The effect could not be downloaded because essential information is missing.  For example, no axes have been associated with the effect, or no type-specific information has been created. & One of the specified pins supports no media types.";
                break;
            case -2147220985:
                result = "Attempted to read buffered device data from a device that is not buffered. & There is no common media type between these pins.";
                break;
            case -2147220984:
                result = "An attempt was made to modify parameters of an effect while it is playing.  Not all hardware devices support altering the parameters of an effect while it is playing. & Two pins of the same direction cannot be connected together.";
                break;
            case -2147220983:
                result = "The operation could not be completed because the device is not plugged in. & The operation cannot be performed because the pins are not connected.";
                break;
            case -2147220982:
                result = "SendDeviceData failed because more information was requested to be sent than can be sent to the device.  Some devices have restrictions on how much data can be sent to them.  (For example, there might be a limit on the number of buttons that can be pressed at once.) & No sample buffer allocator is available.";
                break;
            case -2147220981:
                result = "A mapper file function failed because reading or writing the user or IHV settings file failed. & A run-time error occurred.";
                break;
            case -2147220980:
                result = "No buffer space has been set";
                break;
            case -2147220979:
                result = "The buffer is not big enough.";
                break;
            case -2147220978:
                result = "An invalid alignment was specified.";
                break;
            case -2147220977:
                result = "Cannot change allocated memory while the filter is active.";
                break;
            case -2147220976:
                result = "One or more buffers are still active.";
                break;
            case -2147220975:
                result = "Cannot allocate a sample when the allocator is not active.";
                break;
            case -2147220974:
                result = "Cannot allocate memory because no size has been set.";
                break;
            case -2147220973:
                result = "Cannot lock for synchronization because no clock has been defined.";
                break;
            case -2147220972:
                result = "Quality messages could not be sent because no quality sink has been defined.";
                break;
            case -2147220971:
                result = "A required interface has not been implemented.";
                break;
            default:
                return "n/a";
            }
        }
    }
    return result;
}

/*
==============
R_ErrorDescription
==============
*/
const char *R_ErrorDescription(int hr)
{
	return DXGetErrorDescriptionA(hr);
}

/*
==============
R_IsNullRenderer
==============
*/
bool R_IsNullRenderer()
{
    return 1; // ?
}

/*
==============
R_GetFontPathFromName
==============
*/
char *R_GetFontPathFromName(const char *fontName)
{
    assert(fontName);
    assert(fontName[0]);
    return va("fonts/%d/%s", Dvar_GetInt(r_fontResolution), fontName);
}

/*
==============
R_SetBrightness
==============
*/
void R_SetBrightness(float brightness)
{
    if (rg.gamma != brightness)
    {
        Dvar_SetFloat(r_brightness, brightness);
        rg.gamma = brightness;
        rg.gammaModified = 1;
    }
}

/*
==============
R_SetColorMappings
==============
*/
void R_SetColorMappings()
{
    GfxGammaRamp gammaRamp;

    if (vidConfig.deviceSupportsGamma)
    {
        RB_SetGammaRamp(&gammaRamp);
    }
}

/*
==============
R_GammaCorrect
==============
*/
void R_GammaCorrect(unsigned __int8 *buffer, int bufSize)
{
    int i;
    GfxGammaRamp gammaRamp;

    assert(buffer);
    assert(!(bufSize <= 0));
    for (i = 0; i < bufSize; ++i)
        buffer[i] = 255 * gammaRamp.entries[buffer[i]] / 0xFFFF;
}

/*
==============
SetGfxConfig
==============
*/
void SetGfxConfig(const GfxConfiguration *config)
{
    assert(config);
    gfxCfg = *config;
}

/*
==============
R_MakeDedicated
==============
*/
void R_MakeDedicated(const GfxConfiguration *config)
{
    SetGfxConfig(config);
    if (!r_loadForRenderer)
    {
        R_RegisterDvars();
    }
    Dvar_SetBool(r_loadForRenderer, false);
    Dvar_MakeLatchedValueCurrent(r_loadForRenderer);
    DB_LoadGraphicsAssetsForPC();
}

/*
==============
R_Is3DOn
==============
*/
bool R_Is3DOn()
{
    return r_3dmode;
}

/*
==============
R_SetVidRestart
==============
*/
void R_SetVidRestart()
{
    if ((Dvar_HasLatchedValue(r_mode) || Dvar_HasLatchedValue(r_fullscreen) || Dvar_HasLatchedValue(r_aaSamples) || Dvar_HasLatchedValue(r_monitor)) && !R_Is3DOn())
        dx.vidRestart = 1;
}

/*
==============
R_AllocateMinimalResources
==============
*/
void R_AllocateMinimalResources()
{
    g_allocateMinimalResources = 1;
}

/*
==============
R_SetIsMultiplayer
==============
*/
void R_SetIsMultiplayer(bool isMp)
{
	r_glob.isMultiplayer = isMp;
}

/*
==============
R_SetIsZombie
==============
*/
void R_SetIsZombie(bool isZM)
{
	r_glob.isZombie = isZM;
}

/*
==============
R_ShutdownStreams
==============
*/
void R_ShutdownStreams()
{
	if (dx.device)
		R_ClearAllStreamSources(&gfxCmdBufState.prim);
}

/*
==============
R_ShutdownInternal
==============
*/
void R_ShutdownInternal()
{

}

/*
==============
R_Shutdown
==============
*/
void R_Shutdown(int destroyWindow)
{
	g_destroy_window = destroyWindow;
	Sys_SetD3DShutdownEvent();
	while (Sys_QueryD3DShutdownEvent())
	{
		NET_Sleep(0);
	}
}

/*
==============
R_UnloadWorld
==============
*/
void R_UnloadWorld()
{
	assert(IsFastFileLoad());
	if (rgp.world)
	{
		Sys_Error("Cannot unload bsp while it is in use");
	}
	rgp.postMapFastfileLoadFinished = 0;
}

/*
==============
R_BeginRegistration
==============
*/
void R_BeginRegistration(vidConfig_t *vidConfigOut)
{
#if !XENON
	Sys_SetRGRegisteredEvent();
	while (Sys_QueryRGRegisteredEvent())
	{
		Sys_CheckQuitRequest();
		NET_Sleep(0);
	}
#else
	R_Init();
#endif
	assert(vidConfigOut);
	memcpy(vidConfigOut, &vidConfig, sizeof(vidConfig_t));
	assert(!r_glob.startedRenderThread);
	r_glob.startedRenderThread = 1;
#if XENON
	R_ReleaseThreadOwnership();
#endif
}

/*
==============
R_EndRegistration
==============
*/
void R_EndRegistration()
{
	assert(rg.registered)
	if (!Dvar_GetBool(useFastFile))
	{
		R_SyncRenderThread();
		RB_TouchAllImages();
	}
}

/*
==============
R_TrackStatistics
==============
*/
void R_TrackStatistics(trStatistics_t *stats)
{
	rg.globalstats = stats;
}

/*
==============
R_ConfigureRenderer
==============
*/
void R_ConfigureRenderer(const GfxConfiguration *config)
{
	SetGfxConfig(config);
	R_InitRenderCommands();
}

/*
==============
R_StereoActivated
==============
*/
bool R_StereoActivated()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_Init
==============
*/
void R_Init()
{

}

/*
==============
R_InitOnce
==============
*/
void R_InitOnce()
{
	;
}

/*
==============
R_InitThreads
==============
*/
void R_InitThreads()
{
	assert(!r_glob.isRenderingRemoteUpdate);
	Com_Printf(CON_CHANNEL_GFX, "Trying SMP acceleration...\n");
	R_InitRenderThread();
	R_InitWorkerCmds();
}

