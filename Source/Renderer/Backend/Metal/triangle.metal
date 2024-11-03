#include <metal_stdlib>
            using namespace metal;

            struct v2f
            {
                float4 position [[position]];
                half3 color;
            };

            struct VertexData
            {
                device float3* positions [[id(0)]];
                device float3* colors [[id(1)]];
            };

            v2f vertex vertexFunction( device const VertexData* vertexData [[buffer(0)]], uint vertexId [[vertex_id]] )
            {
                v2f o;
                o.position = float4( vertexData->positions[ vertexId ], 1.0 );
                o.color = half3(vertexData->colors[ vertexId ]);
                return o;
            }

            half4 fragment fragmentFunction( v2f in [[stage_in]] )
            {
                return half4( in.color, 1.0 );
            }