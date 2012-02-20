/*
    genieutils - <description>
    Copyright (C) 2011  Armin Preiml <email>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "genie/file/Compressor.h"

#include <vector>

#include <boost/interprocess/streams/vectorstream.hpp>
#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/iostreams/filter/zlib.hpp>
#include <boost/iostreams/device/back_inserter.hpp>
#include <boost/iostreams/copy.hpp>

using namespace boost;
using namespace boost::iostreams;

namespace genie
{
  
typedef boost::interprocess::basic_vectorstream< std::vector<char> > v_stream;

//------------------------------------------------------------------------------
Compressor::Compressor()
{
  istream_ = 0;
}

//------------------------------------------------------------------------------
Compressor::~Compressor()
{
}
  
//------------------------------------------------------------------------------
shared_ptr<std::istream> Compressor::startDecompression(std::istream *istr)
{
  istream_ = istr;
  
  try
  {
    filtering_istreambuf in;
    
    // register decompressor
    in.push(zlib_decompressor(getZlibParams()));
    
    in.push(*istr);
        
    // extract file to buffer
    std::vector<char> file_buf;
    back_insert_device< std::vector<char> > b_ins(file_buf); 
    
    copy(in, b_ins);
    
    uncompressedIstream_ = shared_ptr<std::istream>(new v_stream(file_buf)); 
    return uncompressedIstream_;
  }
  catch ( const zlib_error &z_err)
  {
    uncompressedIstream_.reset();
    std::cerr << "Zlib decompression failed with error code: "
              <<  z_err.error() << std::endl;
    throw z_err;
  }
  
  return shared_ptr<std::istream>();
}

//------------------------------------------------------------------------------
std::istream *Compressor::stopDecompression(void)
{
  uncompressedIstream_.reset();
  
  std::istream *ret_istr = istream_;
  istream_ = 0;
  
  return ret_istr;
}

std::iostream *Compressor::startCompression(std::ostream *ostr)
{
  std::vector<char> file_buf;
  
  //return std::auto_ptr<std::iostream> (new v_stream(file_buf));
  return new v_stream(file_buf);
}

std::ostream *Compressor::stopCompression(std::istream *istr)
{/*
  try
  {
    filtering_ostreambuf out;
    
    out.push(zlib_compressor(getZlibParams()));
    
    out.push(*istream_);
    
    copy (istr, out);
    
  }
  catch (const zlib_error &z_err)
  {
    std::cerr << "Zlib compression failed with error code: "
              <<  z_err.error() << std::endl;
    throw z_err;
  }*/
}

//------------------------------------------------------------------------------
boost::iostreams::zlib_params Compressor::getZlibParams(void ) const
{  
  zlib_params params;
  
  // important
  params.window_bits = -15;
  
  // default
  params.level = -1;
  params.method = zlib::deflated;
  params.mem_level = 9;
  params.strategy = zlib::default_strategy;
  
  return params;
}
  
}