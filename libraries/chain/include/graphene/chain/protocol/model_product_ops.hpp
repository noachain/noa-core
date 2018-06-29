/*#ifndef MODEL_PRODUCT_OPS_H
#define MODEL_PRODUCT_OPS_H



#endif // MODEL_PRODUCT_OPS_H
*/
#pragma once

#include <graphene/chain/protocol/base.hpp>
#include <graphene/chain/protocol/buyback.hpp>
#include <graphene/chain/protocol/ext.hpp>
#include <graphene/chain/protocol/special_authority.hpp>
#include <graphene/chain/protocol/types.hpp>
#include <graphene/chain/protocol/vote.hpp>
#include <graphene/chain/model_product_object.hpp>
namespace graphene
{
    namespace  chain
    {
        struct model_product_create_operation : public base_operation
        {
            struct fee_parameters_type
            {
                uint64_t fee = GRAPHENE_BLOCKCHAIN_PRECISION/10000;
            };
            fc::string                              request_id;
            object_id_type                          model_id;
            fc::string                              ipfs_hash;
            asset                                   fee;
            account_id_type                         requester;
            time_point_sec                          create_date_time;
           // fc::optional<model_product_id_type>     model_product_id = fc::optional<model_product_id_type>();
            account_id_type fee_payer() const
            {
                return requester;
            }
            void validate() const
            {
            }

            fc::string get_request_id() const
            {
                return request_id;
            }

            share_type calculate_fee( const fee_parameters_type& k ) const
            {
                return k.fee;
            }
        };

        struct model_product_update_operation:public base_operation
        {
            struct fee_parameters_type
            {
                uint64_t fee =0;
            };
            fc::string                                      request_id;
            uint8_t                                         new_status = 0;
            account_id_type                                 new_requester;
            asset                                           fee;
            fc::optional<fc::string>                        new_memo = fc::optional<fc::string>();
            extensions_type                                 extensions;


            account_id_type fee_payer() const { return new_requester; }
            void            validate() const{ }
            share_type      calculate_fee(const fee_parameters_type& k) const{
                return k.fee;
            }

        };
    }
}

FC_REFLECT( graphene::chain::model_product_create_operation::fee_parameters_type, (fee) )
FC_REFLECT( graphene::chain::model_product_update_operation::fee_parameters_type, (fee) )

FC_REFLECT( graphene::chain::model_product_create_operation,
            (request_id)
            (model_id)
            (ipfs_hash)
            (fee)
            (requester)
            (create_date_time)
)
FC_REFLECT( graphene::chain::model_product_update_operation,
            (request_id)
            (new_status)
            (new_requester)
            (fee)
            (new_memo)
            (extensions)
)
