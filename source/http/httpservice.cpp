/*
	Copyright (c) 2018 Willem Kemp, willem@eneritix.co.za

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
 */

#include "shrike/http/httpservice.h"

#include "tokenizer.h"
#include "shrike/http/httprequest.h"
#include "shrike/http/httpresponse.h"

#include "httpservice_impl.h"

#include <list>
#include <memory>
#include <vector>


namespace shrike
{

http_service::http_service(int port) :
	_pimpl(new http_service::impl(port))
{

}

http_service::~http_service()
{
	delete _pimpl;
}

http_response http_service::dispatch(const http_request& request)
{
	return _pimpl->dispatch(request);
}

void http_service::register_method(const std::string& uri, std::function<http_response(const http_request&)> func)
{
	_pimpl->register_method(uri, func);
}

}
