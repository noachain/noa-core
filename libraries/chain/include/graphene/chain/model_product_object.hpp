/*#ifndef MODEL_PRODUCT_OPS_H
#define MODEL_PRODUCT_OPS_H

#endif // MODEL_PRODUCT_OPS_H*/
#pragma once
#include <graphene/db/generic_index.hpp>
//#include <graphene/chain/schema_context_object.hpp>
#include <graphene/chain/protocol/operations.hpp>
#include <boost/multi_index/composite_key.hpp>
#include <vector>

namespace  graphene
{
    namespace chain
    {
        using namespace std;
        struct model_product_status_object
        {
            account_id_type         model_product;
            uint8_t                 status;
        };
        class model_product_object : public graphene::db::abstract_object<model_product_object>
        {
        public:
            static const uint8_t space_id = protocol_ids;
            static const uint8_t type_id = model_product_object_type;
            string                                      model_name;
            string                                      ipfs_hash;
            uint8_t                                     status =0;
            time_point_sec                              create_date_time;
            account_id_type                             requester;
            //fc::optional<model_market_id_type>          model_market_id = fc::optional<model_market_id_type>;
            string                                      memo;
            uint64_t                                    product_pay = 0 ;
            uint64_t                                    transaction_fee = 0;
            uint64_t                                    commission = 0;
        };

        struct sort_model_product_object_by_create_time
        {
            bool operator () (const model_product_object&l,const model_product_object&r)
            {
                return l.create_date_time > r.create_date_time;
            }
        };

        class model_product_search_result_object : public graphene::db::abstract_object<model_product_search_result_object>
        {
          public:
            static const uint8_t space_id = implementation_ids;
            static const uint8_t type_id = impl_model_product_search_result_object_type;
           /* account_id_type                                     requester;
            account_id_type                                     modelsource;
            string                                              model_product_request_id;
            //string                                              merchant_copyright_hash;
            //string                                              model_copyright_hast;
            time_point_sec                                      create_date_time;*/

            uint64_t total = 0;
            vector <model_product_object> data;
        };

        class model_product_complain_object : public graphene::db::abstract_object<model_product_complain_object>
        {
          public:
                static const uint8_t space_id = protocol_ids;
                static const uint8_t type_id = model_product_complain_object_type;

                account_id_type             requester;
                account_id_type             modelsource;
                string                      model_product_request_id;

                time_point_sec              create_date_time;
        };

        struct by_id_model{};
        struct by_request_id_model{};
        struct by_create_date_time_model{};
        struct by_requester_model{};

        using model_product_multi_index_type = multi_index_container<
            model_product_object,
            indexed_by<
                ordered_unique< tag<by_id_model>,member< object,object_id_type,&object::id> >,
                ordered_non_unique< tag<by_create_date_time_model>, member<model_product_object,time_point_sec,&model_product_object::create_date_time> >,
                ordered_non_unique< tag<by_requester_model>,
                    member<model_product_object,account_id_type,&model_product_object::requester>
                >,
                ordered_unique< tag<by_request_id_model>,
                    composite_key<
                        model_product_object,
                        member<model_product_object,string,&model_product_object::model_name>,
                        member<model_product_object,time_point_sec,&model_product_object::create_date_time>
                    >,
                    composite_key_compare<std::less<string> ,std::less<time_point_sec> >
                >
            >
        >;

        using model_product_index = generic_index<model_product_object,model_product_multi_index_type>;

        using model_product_complain_multi_index_type = multi_index_container<
            model_product_complain_object,
            indexed_by<
                ordered_unique< tag<by_id_model>,member< object,object_id_type,&object::id > >,
                ordered_non_unique< tag< by_create_date_time_model >,member< model_product_complain_object,time_point_sec,&model_product_complain_object::create_date_time> >,
                ordered_unique< tag<by_request_id_model>,member<model_product_complain_object,string,&model_product_complain_object::model_product_request_id> >
            >
        >;
        using model_product_complain_index = generic_index<model_product_complain_object,model_product_complain_multi_index_type>;
    }
}

FC_REFLECT( graphene::chain::model_product_status_object,
            (model_product)
            (status)
        )
FC_REFLECT_DERIVED( graphene::chain::model_product_complain_object,
            (graphene::db::object),
            (requester)
            (modelsource)
            (model_product_request_id)
            (create_date_time)
 )

FC_REFLECT_DERIVED(graphene::chain::model_product_object,
                   (graphene::db::object),
                   (model_name)
                   (ipfs_hash)
                   (status)
                   (create_date_time)
                   (requester)
                   (memo)
                   (product_pay)
                   (transaction_fee)
                   (commission))
FC_REFLECT_DERIVED(graphene::chain::model_product_search_result_object,
                   (graphene::db::object),
                   (total)
                   (data))
