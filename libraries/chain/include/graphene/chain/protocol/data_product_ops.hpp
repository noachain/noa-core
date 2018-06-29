//#ifndef DATA_PRODUCT_OPS_HPP
//#define DATA_PRODUCT_OPS_HPP
#pragma once
#include <graphene/chain/protocol/base.hpp>
#include <graphene/chain/protocol/buyback.hpp>
#include <graphene/chain/protocol/ext.hpp>
#include <graphene/chain/protocol/special_authority.hpp>
#include <graphene/chain/protocol/types.hpp>
#include <graphene/chain/protocol/vote.hpp>
#include <graphene/chain/data_product_object.hpp>
namespace  graphene
{
    namespace chain
    {
        struct data_product_create_operation : public base_operation
        {
            struct fee_parameters_type
            {
                uint64_t fee = 0;
            };

            fc::string                              request_id;
            object_id_type                          product_id;
            fc::string                              version;
            fc::string                              params;
            asset                                   fee;
            account_id_type                         requester;
            time_point_sec                          create_data_time;
          //  fc::optional<data_product_id_type>      data_product_id = fc::optional<data_product_id_type>();
            extensions_type                         extensions;

            account_id_type fee_payer()const {return requester;}
            fc::string get_request_id() const
            {
                return request_id;
            }

            share_type calculate_fee(const fee_parameters_type &k) const
            {
                return k.fee;
            }
        };

        struct data_product_update_operation : public base_operation
        {
            struct fee_parameters_type
            {
                uint64_t fee  = 0;
            };
            fc::string                                      request_id;
            uint8_t                                         new_status = 0;
            account_id_type                                 new_requester;
            asset                                           fee;
            fc::optional<fc::string>                        new_memo = fc::optional<fc::string>();
            extensions_type                                 extensions;


            account_id_type fee_payer() const
            {
                return new_requester;
            }
            void            validate() const{ }
            share_type      calculate_fee(const fee_parameters_type& k) const
            {
                return k.fee;
            }
        };
    }
}

FC_REFLECT(  graphene::chain::data_product_create_operation::fee_parameters_type, (fee) )
FC_REFLECT(  graphene::chain::data_product_update_operation::fee_parameters_type, (fee) )

FC_REFLECT( graphene::chain::data_product_create_operation,
            (request_id)
            (product_id)
            (version)
            (params)
            (fee)
            (requester)
            (create_data_time)
            (extensions)
)

FC_REFLECT( graphene::chain::data_product_update_operation,
            (request_id)
            (new_status)
            (fee)
            (new_requester)
            (new_memo)
            (extensions)
)


//#endif // DATA_PRODUCT_OPS_HPP
