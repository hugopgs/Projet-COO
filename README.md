# Rigid Alignment Images Processing

This project is designed to perform rigid alignment of images using various interpolation and similarity methods. The main goal is to align a floating image to a reference image by finding the optimal transformation parameters that minimize the difference between the two images.

## Project Structure

The project is organized into the following directories:

- **include/**: Contains header files for various classes and methods used in the project.
- **src/**: Contains the implementation of the classes and methods defined in the header files.
- **floating.pgm**: The floating image that needs to be aligned.
- **reference.pgm**: The reference image to which the floating image will be aligned.

## Key Components

### Interpolation

Interpolation is used to estimate the pixel values at non-integer coordinates during the transformation process. The project includes two interpolation methods:

- **InterpolationDefault**: Performs bilinear interpolation.
- **InterpolationPpv**: Performs nearest-neighbor interpolation.

### Similarity

Similarity measures the difference between the reference image and the transformed floating image. The project includes two similarity methods:

- **SimilariteDefault**: Computes the mean squared error between the reference and transformed images.
- **SimilariteMutualInformation**: Computes the mutual information between the reference and transformed images.

### Transformation

The transformation class is responsible for applying the rigid transformation to the floating image. The transformation parameters include translation in x and y directions and rotation.

### Deformation

The deformation class applies the transformation to the floating image and uses the specified interpolation method to compute the pixel values of the transformed image.

### Optimization

The optimization process uses the Amoeba method to find the transformation parameters that minimize the similarity measure. The `Cout` class computes the cost (similarity) for a given set of transformation parameters.

## Usage

The main entry point of the project is the `main.cpp` file, which performs the following steps:

1. Reads the floating and reference images.
2. Initializes the interpolation and similarity methods.
3. Uses the `Recalage` class to find the optimal transformation parameters.
4. Applies the transformation to the floating image.
5. Writes the transformed image to a file.

### Example

To run the project, compile and execute the `main.cpp` file. The output will include the optimal transformation parameters and the transformed image saved to a file.

```cpp
int main() {
    Recalage r;
    string f = "floating.pgm", fRef = "reference.pgm", fppv = "imageDefPpv.pgm", fDef = "imageDef.pgm";
    InterpolationPpv interpppv;
    InterpolationDefault interpDef;
    SimilariteDefault sim;

    cout << "---------------------Interp PPV---------------------" << endl;
    VecDoub u = r.getThetaMax(f, fRef, fppv, &sim, &interpppv);

    cout << "---------------------Interp Default---------------------" << endl;
    u = r.getThetaMax(f, fRef, fDef, &sim, &interpDef);

    return 0;
}
```
## Dependencies
- C++ Standard Library
-  NR3 library for numerical recipes

## Compilation
Use a C++ compiler to compile the project. Ensure that all source and header files are included in the compilation.

## License
This project is licensed under the MIT License. See the LICENSE file for details.


## Authors
Hugo PAGÈS, Emma De Faria, Clémence Deviller, Lucile Petronin - 2023 ```