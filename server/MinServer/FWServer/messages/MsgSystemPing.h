#ifndef MsgSystemPing_h__
#define MsgSystemPing_h__


#include "MinMessage.h"
#include "../FWSMessageIDs.h"

// %%GENERATOR_START%%MSG_IMPL_USER_HEADERS%%
#include <iostream>
// %%GENERATOR_END%%MSG_IMPL_USER_HEADERS%%

namespace fws {

/**
 * System ping message.
 */

class MsgSystemPing : public min::MinMessage {


	public:


		MsgSystemPing(bool init = true) {
			msgId = FWSMessageIDs::MSGID_SYSTEM_PING;
			_msgMinLength = 4;
			length = _msgMinLength;
			if (init) {initDefaultValues();}
			_msgIsValid = true;
		}

		MsgSystemPing(const unsigned char* buf) {
			msgId = FWSMessageIDs::MSGID_SYSTEM_PING;
			_msgMinLength = 4;
			_msgIsValid = true;
			valuesFromBytes(buf);
		}

		MsgSystemPing(const unsigned char* buf, unsigned int totalLength) {
			msgId = FWSMessageIDs::MSGID_SYSTEM_PING;
			_msgMinLength = 4;
			_msgIsValid = true;
			length = totalLength;
			if (_msgMinLength <= length) {
				valuesFromBytes(buf, false);
			} else {
				_msgIsValid = false;
			}
		}

		virtual ~MsgSystemPing() {}

		inline void initDefaultValues() {
		}

		bool valuesFromBytes(const unsigned char* bytes, bool readLength = true) {
			if (readLength) {
				length = min::NetPort::uintFromByte(bytes, 0);
				if (length < _msgMinLength) {
					_msgIsValid = false;
					return false;
				}
			}
			//msgId = min::NetPort::uintFrom3Bytes(bytes, 1);
			return true;
		}

		bool valuesToBytes(unsigned char* bytes, bool validateLength = true) {
			if (validateLength && !checkValidateLength()) {
				return false;
			}
			min::NetPort::uintToByte(length, bytes, 0);
			min::NetPort::uintTo3Bytes(msgId, bytes, 1);
			return true;
		}

		inline bool checkValidateLength() {
			length = _msgMinLength ;
			return true;
		}

		inline bool isValid() {
			return _msgIsValid;
		}

	// %%GENERATOR_START%%MSG_IMPL_USER_CONTENT%%
	// %%GENERATOR_END%%MSG_IMPL_USER_CONTENT%%

};

}

#endif
