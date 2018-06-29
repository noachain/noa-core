/*#ifndef DATA_PRODUCT_EVALUATO_HPP
#define DATA_PRODUCT_EVALUATO_HPP

#endif // DATA_PRODUCT_EVALUATO_HPP
*/
#pragma once
#include <graphene/chain/protocol/operations.hpp>
#include <graphene/chain/evaluator.hpp>
#include <graphene/chain/database.hpp>
#include <graphene/chain/data_product_object.hpp>

namespace  graphene
{
    namespace   chain
    {
        class data_product_create_evaluator : public evaluator<data_product_create_evaluator>
        {
        public:
            typedef data_product_create_operation operation_type;
            void_result do_evaluate(const data_product_create_operation&o);
            object_id_type do_apply(const data_product_create_operation&o);
        };

        class data_product_update_evaluator : public evaluator<data_product_update_evaluator>
        {
        public:
                typedef data_product_update_operation operation_type;
                void_result do_evaluate(const data_product_update_operation&o);
                object_id_type do_apply(const data_product_update_operation&o);
        };
    }
}
