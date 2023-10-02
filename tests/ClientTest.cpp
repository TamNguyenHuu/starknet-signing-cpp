#include "Account.hpp"

int main()
{
    using namespace starkware;
    using namespace signer;

    std::string url = "https://api.testnet.paradex.trade/v1/auth";
    const std::string chainId = "PRIVATE_SN_POTC_GOERLI";
    const auto address = 0x37e671e3cad5b5f9a9a5f8bf33bf34710aeb0ef326eb2f74ce361ac04e4e74f_Z;
    constexpr BigInt< 4 > privateKey = 0x02437f43467dd0a91da072cf0cbb3daa4e602707b7df7b225058500b637ed6b2_Z;

    KeyPair keyPair( privateKey );
    Account account( PrimeFieldElement::FromBigInt( address ), chainId, keyPair );

    std::string response = account.getJwtToken( url );
    std::cout << response << std::endl;

    return 0;
}

