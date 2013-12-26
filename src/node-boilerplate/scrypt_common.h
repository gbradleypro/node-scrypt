/*
scrypt_common.cc

Copyright (C) 2013 Barry Steyn (http://doctrina.org/Scrypt-Authentication-For-Node.html)

This source code is provided 'as-is', without any express or implied
warranty. In no event will the author be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

1. The origin of this source code must not be misrepresented; you must not
claim that you wrote the original source code. If you use this source code
in a product, an acknowledgment in the product documentation would be
appreciated but is not required.

2. Altered source versions must be plainly marked as such, and must not be
misrepresented as being the original source code.

3. This notice may not be removed or altered from any source distribution.

Barry Steyn barry.steyn@gmail.com

*/

//Constants
const uint8_t JSARG=1; //Error in JavaScript land: Argument mismatch
const uint8_t INTERNARG=2; //Error resulting from argument mismatch in index.js
const uint8_t SCRYPT=3; //Scrypt generated errors

namespace Internal {
	//
	//  Holds N,r and p parameters
	//
	struct ScryptParams {
		int N;
		uint32_t r;
		uint32_t p;

		void operator=(const v8::Local<v8::Object>& rhs);
	};

	//
	//Declarations
	//
	int CheckScryptParameters(const v8::Local<v8::Object>&, std::string&);
	v8::Local<v8::Value> MakeErrorObject(int, const char*);
	v8::Local<v8::Value> MakeErrorObject(int, int);
	void CreateBuffer(v8::Handle<v8::Value>&, size_t);
}
