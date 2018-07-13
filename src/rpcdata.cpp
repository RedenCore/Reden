/*
 * rpcdata.cpp
 *
 *  Created on: Jun 3, 2018
 *      Author: tri
 *
 *      referebce docs: https://docs.google.com/drawings/d/1JhzNku4izyAU1QJOFDjbqBVAT8cN_QcWM8Ffinw5GBo
 */

#include "rpcdata.h";
#include "init.h";
#include "main.h"
#include "base58.h"
#include <stdint.h>
#include <univalue.h>

using namespace std;

/**
 * @params pairs of key and values for input
 *    optional key ="address" - value = "reden  address" where data will be store as transaction
 *             if there is no address is provided, this call will generate one.
 *    key = "data" - value = "main message body of this data" it is a key value pair for data type.
 *       there are 6 different data types: Project/Coin Name, Project Specs, Comments, System rating info,
 *                                         MN Rating Info, and Public rating Info
 *       main message can be a json string if it has more complex data structure.
 *       For example: {Project Name : Reden}.
 *                    {Project Specs:
 *                                   { Supply: 14000000,
 *                                     POW Algo: x16s,
 *                                     Masternode collateral : 5000,
 *                                     Ticket: REDN,
 *                                     Github: http://github/RedenCore/Reden,
 *                                   }
 *                    }
 *    return reden wallet address of where data were store successfully, "null" other wise
 *
 */
UniValue createandsavedata(const UniValue& params, bool fHelp) {
	// RPCTypeCheck(params, boost::assign::list_of(UniValue::VOBJ),true);
	 throw runtime_error("to be implemented");
	 /*
	 if(params.size() > 0) {
		 UniValue inputObj = params[0].get_obj();
		 UniValue addrValue = inputObj["address"];
		 UniValue data = inputObj["data"];
		 if(data.isNull()) {
			 throw runtime_error("missing data");
		 }
		 UniValue projectNameValue = data["Project Name"];
		 if(projectNameValue.isNull()) {
			 throw runtime_error("Project Name is required");
		 }
		 string projectName = projectNameValue.getValStr();
		 string redenAddr = getRedenAddress(addrValue);
		 CMutableTransaction rawTx;

		 //CBitcoinAddress address(redenAddr);

	 }*/
}

string getRedenAddress(const UniValue& addrValue) {
	string redenAddr;
	if(addrValue.isNull()) {
		 UniValue newAddrParams;
		 UniValue newAddrResult = getnewaddress(newAddrParams);
		 redenAddr = newAddrResult[0].getValStr();
	 } else if(addrValue.isStr()){
		 redenAddr = addrValue.getValStr();
	 } else {
		 throw runtime_error("reden address is invalid");
	 }
	 CBitcoinAddress address(redenAddr);

	return redenAddr;
}


/**
 * @params pairs of key and values for input
 *    key ="address" - value = "reden  address" where data was store as transaction
 *             if there is no address is provided, this call will generate one.
 *    key = "data type" - value = "main message body of this data" it is a key value pair for data type.
 *       there are 6 different data types: Project/Coin Name, Project Specs, Comments, System rating info,
 *                                         MN Rating Info, and Public rating Info
 *       main message can be a json string if it has more complex data structure.
 *       For example: {Project Name : Reden}.
 *                    {Project Specs:
 *                                   { Supply: 14000000,
 *                                     POW Algo: x16s,
 *                                     Masternode collateral : 5000,
 *                                     Ticket: REDN,
 *                                     Github: http://github/RedenCore/Reden,
 *                                   }
 *                    }
 *    throw an error with this wallet address is not used to stored data. this can be done by detect a transaction with Project name header.
 *    if there is no such transaction then it is not a wallet address.
 *    return reden wallet address of where data were edit successfully, "null" other wise
 *
 */
UniValue updatedata(const UniValue& params, bool fHelp) {
	 throw runtime_error("to be implemented");
}
/**
 * @params search query in a form of key value pair. search all data belong to a reden wallet address with a data type.
 *   {"address" : "reden wallet address",
 *    "query" : "data type"}
 *    return data in a json string format
 */
UniValue searchdata(const UniValue& params, bool fHelp) {
	 throw runtime_error("to be implemented");
}



