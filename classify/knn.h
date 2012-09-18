/**
 * @file knn.h
 */

#ifndef _KNN_H_
#define _KNN_H_

#include <map>
#include <memory>
#include <vector>
#include <string>
#include "index/index.h"

class Document;

/**
 * Runs KNN on a single index or multiple indexes.
 */
namespace KNN
{
    /**
     * Runs a KNN classifier.
     * @param query - the query to run
     * @param index - the index to perform the KNN on
     * @param k - the value of k in KNN
     */
    std::string classify(Document & query, std::shared_ptr<Index> index, size_t k);

    /**
     * Runs a KNN classifier.
     * @param query - the query to run
     * @param index - the indexes to perform the KNN search on
     * @param weights - ensemble linear interpolation weights
     * @param k - the value of k in KNN
     */
    std::string classify(Document & query,
            std::vector<std::shared_ptr<Index>> indexes,
            std::vector<double> weights,
            size_t k);

    namespace internal
    {
        /**
         * Normalizes the values in scores to be in [0, 1].
         * @param scores - the scores to normalize
         * @return the normalized scores
         */
        std::multimap<double, std::string>
        normalize(const std::multimap<double, std::string> & scores);
    }
}

#endif